#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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
    sprintf(cpCommand, "cp %s %s%s", fileName, "BackingStore/", fileName);
    system(cpCommand);

    // Close the file pointer pointing to the original file
    fclose(p);

    // Open the file in the backing store
    char file_dir[40];
    //Get the file path
    sprintf(file_dir, "%s%s", "BackingStore/", fileName);
    //Open file
    FILE* file = fopen(file_dir, "r");

    printf("%s%s\n", "File is successfully stored ", fileName);


    // Call myInit to make pcb and add it to ready list
    int numPages = countTotalPages(file);

    int successCode = myinit(fileName);

    if (successCode == 0) {
        // Count total Pages

        // Find frame number
        int frameNumber = findFrame();
//        PCB* pcb = head->pcb;
        PCB* pcb = getPCBfromReady();
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
        pcb->filename = fileName;
        pcb->PC = frameNumber*4;
        pcb->PC_offset = 0;
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
//            pcb->PC_page++;
            loadPage(pcb->PC_page+1, file, frame_number);
            updatePageTable(pcb, pcb->PC_page+1, frame_number, victim_Frame);
        }

        addToReady(pcb);

        return 1;
    }

    // launcher() function returns a 1 if it was successful launching the program,
    // otherwise it returns 0.

    return 0;
}

/**
 * @param f file
 * @return total number of pages needed by the program
 */
int countTotalPages(FILE *f) {
    int ch;
    int count = 0;
    start = end+1;

    while (!feof(f)) {
        ch = fgetc(f);
        if (ch == '\n') {
            count++;
        }
    }

    printf("%s%d\n", "count is ", count);
    end = start+count-1;
    fseek(f, 0, SEEK_SET);

    double num = count;
    count = ceil(num / 4);
    if (count == 0) {count = 1; }
    printf("%s%d\n", "Total pages are ", count);
    printf("%s%d\n", "Start in count page is ", start);
    printf("%s%d\n", "End in count page is ", end);

    return count;
}


/**
 * The function loads the 4 lines of code from the page into the frame in ram[]
 * @param pageNumber desired page from the backing store
 * @param f points to the beginning of the file in the backing store
 * @param frameNumber
 */
void loadPage(int pageNumber, FILE *f, int frameNumber) {
    printf("%s%d\n", "page number is ", pageNumber);

    //    fread(ram[frameNumber], 100, 4, f);

    int count = 0;
    char buffer[MAX_NUM];
    int i = frameNumber * 4;
    printf("%s\n", "Now RAM stores the following...");
    while (fgets(buffer, MAX_NUM, f) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        ram[i] = strdup(buffer);
        printf("%s\n", ram[i]);
        count++;
        if (count == 4) {
            break;
        }
        i++;
    }

//    // For Testing Purpose
//    printf("%s\n", "Now RAM stores the following...");
//    for (int j = frameNumber; j < frameNumber+ 4; j++) {
//        printf("%s\n", ram[j]);
//    }

    fseek(f, pageNumber*4, SEEK_CUR);     // place pointer at the correct position


}

/**
 * Use the FIFO technique to search ram[] for a frame (not equal to NULL).
 * @return index number if exists, otherwise return -1
 */
int findFrame() {
    //TODO: make a frame queue
    //TODO: Check: why no parameter
//    char buffer[MAX_NUM];
//    char line = fgets(buffer, MAX_NUM, file);
    for (int i = 0; i < 40; i+=4) {
        if (ram[i] == NULL) {
            printf("%s%d\n", "Frame number is ", i/4);
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
        if (count < 10) {
            printf("%s%d\n", "VICTIM frame number is ", frameNumber);
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
        printf("%s%d\n", "page table is updated with VICTIM Frame ", victimFrame);
        return victimFrame;
    }
    else {
        p->pageTable[pageNumber] = frameNumber;
        printf("%s%d\n", "page table is updated with frame number ", frameNumber);
        return frameNumber;
    }

}