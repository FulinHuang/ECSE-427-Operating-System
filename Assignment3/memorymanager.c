#include <stdlib.h>
#include <stdio.h>

#include "pcb.h"

int launcher(FILE *p) {

    // launcher() function returns a 1 if it was successful launching the program,
    // otherwise it returns 0.

    return 0;
}

/**
 * @param f file
 * @return total number of pages needed by the program
 */
int countTotalPages(FILE *f) {
    return 0;
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

    return 0;
}

/**
 * This function is only invoke when findFrame() returns a -1
 * @param p
 * @return a fram number as victim
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