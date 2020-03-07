#include <stdlib.h>
#include <stdio.h>

#include "pcb.h"
#include "ram.h"

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

    // Count total Pages
    int numPages = countTotalPages(file);

    // Find frame number
    int frameNumber = findFrame();

    if (frameNumber == -1) {

    }

    //Our launch paging technique defaults to loading two pages of the program into RAM when it
    //is first launched. A page is 4 lines of code. If the program has 4 or less lines of code, then only one page is loaded.
    // If the program has more than 8 lines of code, then only the first
    //two pages are loaded. To do this, implement the following helper functions that exist in the


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

}

/**
 * Use the FIFO technique to search ram[] for a frame (not equal to NULL).
 * @return index number if exists, otherwise return -1
 */
int findFrame() {
    //TODO: make a frame queue
    //TODO: Check: why no parameter
    for (int i = 0; i < BUFFER; i++) {
        if(ram[i] != NULL) {
            return i;
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
    return 0;
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

    // p->pageTable[pageNumber] = frameNumber (or = victimFrame).
    return 0;
}