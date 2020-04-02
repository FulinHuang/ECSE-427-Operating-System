#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pcb.h"
#include "ram.h"
#include "kernel.h"

#define MAX_NUM 100

int countTotalPages(FILE *f);
void loadPage(int pageNumber, FILE *f, int frameNumber);
int findFrame();
int findVictim(PCB *p);
int updatePageTable(PCB *p, int pageNumber, int frameNumber, int victimFrame);


int launcher(FILE *p, char* fileName) {

    // Copy entire file into backing store
    char cpCommand[40];

    int random = rand()%100;

    sprintf(cpCommand, "cp %s %s%d", fileName, "BackingStore/", random);
    system(cpCommand);

    // Close the file pointer pointing to the original file
    fclose(p);

    // Open the file in the backing store
    char file_dir[40];
    //Get the file path
    sprintf(file_dir, "%s%d", "BackingStore/", random);
    //Open file
    FILE* file = fopen(file_dir, "r");

    // Call myInit to make pcb and add it to ready list
    int numPages = countTotalPages(file);
    PCB* pcb = myinit(fileName);

    // Find frame number
    int frameNumber = findFrame();

    int victimFrame = 0;
    if (frameNumber == -1) {
        victimFrame  = findVictim(pcb);
        pcbTable[victimFrame] = pcb;

    }
    else {
        pcbTable[frameNumber] = pcb;

    }

    // Initialize pcb
    pcb->pages_max = numPages;
    pcb->PC_page = 0;  // initialize pc_page
    pcb->PC = frameNumber*4;
    pcb->PC_offset = 0;
    for (int i = 0; i < 10; i++) {
        if (pcbTable[i] != NULL) {
            if (pcb->pid == random) {
                random = random + 1;
            }
        }
    }

    pcb->pid = random;
    for (int i = 0; i < 10; i++) {
        pcb->pageTable[i] = -999;
    }
    loadPage(pcb->PC_page, file, frameNumber);
    updatePageTable(pcb, pcb->PC_page, frameNumber, victimFrame);

    if (numPages > 1) {
        int frame_number = findFrame();
        int victim_Frame = 0;
        if (frame_number == -1) {
            victim_Frame = findVictim(pcb);
            pcbTable[victim_Frame] = pcb;
        }
        else {
            pcbTable[frame_number] = pcb;

        }
        loadPage(pcb->PC_page+1, file, frame_number);
        updatePageTable(pcb, pcb->PC_page+1, frame_number, victim_Frame);

        return 0;
    }

    return 0;
}

/**
 * @param f file
 * @return total number of pages needed by the program
 */
int countTotalPages(FILE *f) {
    int ch;
    int count = 0;

    while (!feof(f)) {
        ch = fgetc(f);
        if (ch == '\n') {
            count++;
        }
    }

    fseek(f, 0, SEEK_SET);
    count = (count / 4) + ((count % 4) != 0);
    if (count == 0) {count = 1; }

    return count;
}


/**
 * The function loads the 4 lines of code from the page into the frame in ram[]
 * @param pageNumber desired page from the backing store
 * @param f points to the beginning of the file in the backing store
 * @param frameNumber
 */
void loadPage(int pageNumber, FILE *f, int frameNumber) {

    int count = 0;
    int j = 0;
    char buffer[MAX_NUM];
    int i = frameNumber * 4;
    while(j < 40 && fgets(buffer, MAX_NUM, f)!= NULL) {

        if (j >= pageNumber * 4 && j < pageNumber * 4 + 4) {
            buffer[strcspn(buffer, "\n")] = '\0';
            ram[i] = strdup(buffer);
            count++;
            i++;

        }
        if (count == 4) {
            break;
        }
        j++;
    }
    while (j < pageNumber * 4 + 4) {
        ram[i] = NULL;
        j++;
        i++;
    }

    fseek(f, 0, SEEK_SET);     // place pointer at the correct position


}

/**
 * Use the FIFO technique to search ram[] for a frame (not equal to NULL).
 * @return index number if exists, otherwise return -1
 */
int findFrame() {

    for (int i = 0; i < 40; i+=4) {
        if (ram[i] == NULL) {
            return i/4;
        }
    }
    return -1;
}

/**
 * This function is only invoke when findFrame() returns a -1
 * @param p
 * @return a frame number as victim
 */
int findVictim(PCB *p) {

    int frameNumber = rand()%10;
    int count = 0;

    while (1) {
        while(count < 10 && frameNumber != p->pageTable[count]) {
            count++;
        }
        if (count == 10) {
            return frameNumber;
        }
        count = 0;

        frameNumber = (frameNumber+1)%10;

    }
}

/**
 *
 * @param p
 * @param pageNumber
 * @param frameNumber
 * @param victimFrame
 * @return
 */
int updatePageTable(PCB *p, int pageNumber, int frameNumber, int victimFrame) {

    if (frameNumber == -1) {
        p->pageTable[pageNumber] = victimFrame;

        for (int i = 0; i < 10; i++) {
            if (pcbTable[i] != NULL && pcbTable[i] != p) {
                PCB* pcb = pcbTable[i];
                for (int j = 0; j < 10; j++) {
                    if (pcb->pageTable[j] == victimFrame) {
                        pcb->pageTable[j] = -999;
                    }

                }
            }
        }

        return victimFrame;
    }
    else {
        p->pageTable[pageNumber] = frameNumber;

        for (int i = 0; i < 10; i++) {
            if (pcbTable[i] != NULL && pcbTable[i] != p) {
                PCB *pcb = pcbTable[i];
                for (int j = 0; j < 10; j++) {
                    if (pcb->pageTable[j] == frameNumber) {
                        pcb->pageTable[j] = -999;
                    }
                }
            }
        }

        return frameNumber;
    }

}