#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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
    sprintf(cpCommand, "cp %s %s%s", fileName, "BackingStore/", fileName);
    system(cpCommand);

    // Close the file pointer pointing to the original file
    fclose(p);

    // Open the file in the backing store
    char file_dir[40];
    //Get the file path
    sprintf(file_dir, "%s%s", "BackingStore/", cpCommand);
    //Open file
    FILE* file = fopen(file_dir, "r");

    // Call myInit to make pcb and add it to ready list
    int successCode = myinit(fileName);

    if (successCode == 0) {
        // Count total Pages
        int numPages = countTotalPages(file);

        // Find frame number
        int frameNumber = findFrame();
        PCB* pcb = head->pcb;
        int victimFrame = -1;
        if (frameNumber == -1) {

//            //Create Page table in RAM
//            for(int i = 0; i < 10; i++) {
//                pcb->pageTable[i] = NULL;
//            }

            victimFrame  = findVictim(pcb);
        }

        pcb->pages_max = numPages;
        pcb->PC_page = 0;  // initialize pc_page
        //TODO: initialize other pcb value ?
//        pcb->PC = 0;
//        pcb->pc_offset = 0;
        loadPage(pcb->PC_page, file, frameNumber);
        updatePageTable(pcb, pcb->PC_page, frameNumber, victimFrame);


        if (numPages > 1) {
            int frame_number = findFrame();
            int victim_Frame = -1;
            if (frame_number == -1) {
                victim_Frame = findVictim(pcb);
            }
            pcb->PC_page++;
            //TODO: update other pcb value ?
//        pcb->PC = ;
//        pcb->pc_offset = ;
            loadPage(pcb->PC_page, file, frame_number);
            updatePageTable(pcb, pcb->PC_page, frameNumber, victim_Frame);
        }
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
    char ch;
    int count = 0;
    while((ch = fgetc(f) != EOF)) {
        if (ch=='\n'){
            count++;
        }
    }
    fseek(f, 0, SEEK_SET);


    fclose(f);

    count = count / 4;
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

    fseek(f, pageNumber, SEEK_SET);     // place pointer at the correct position
    int count = 0;
    char buffer[MAX_NUM];
    int i = frameNumber;
    while (count < 4 && fgets(buffer, MAX_NUM, f) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        ram[i] = strdup(buffer);
        count++;
        i++;
    }
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
        return victimFrame;
    }
    else {
        p->pageTable[pageNumber] = frameNumber;
        return frameNumber;
    }

}