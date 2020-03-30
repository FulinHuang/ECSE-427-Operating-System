#include <stdio.h>
#include <stdlib.h>

#include "pcb.h"
#include "ram.h"
#include "kernel.h"

/*Ready Queue is FIFO and RR*/
PCB* makePCB() {  //creat node

    PCB *pcb = (PCB *) malloc(sizeof(PCB));
    if (pcb == NULL) {
        return NULL;
    }
    else {
//        pcb->PC = start;
//        pcb->start = 0;
//        pcb->end = 0;

        return pcb;
    }
}

void terminatePCB(PCB* pcb){

    printf("%s\n", "BEFORE frame number in pageTABLE is cleared");

    for (int i = 0; i < 10; i++) {
        int frameNumber = pcb->pageTable[i];
        if (frameNumber != -999) {
            for (int j = 0; j < 4; j++) {
                ram[frameNumber*4 + j] = NULL;
            }
        }
    }

    printf("%s\n", "frame number in pageTABLE is cleared");
//    for (int i = 0; i < 40; i++){
//        printf("%s\n", ram[i]);
//    }


    // Remove from pcb table
    for (int i = 0; i < 10; i++) {
        if (pcbTable[i] == pcb) {
            pcbTable[i] = NULL;
        }
    }
    printf("Removed from pcb table\n");

    int fileNumber = pcb->pid;
    pcb = NULL;
    printf("Put pcb null\n");

    free(pcb);
    printf("Freed pcb\n");

//    char* filename = pcb->filename;
    printf("%s%d\n", "file name is ", fileNumber);
    char cpCommand[50];
    sprintf(cpCommand, "rm %s%d", "BackingStore/", fileNumber);
    system(cpCommand);
    printf("File REMOVED\n");


    /**
     * (a) the ram[] cells are assigned NULL for all instructions,
     * (b) the PCB is removed from the Ready Queue, and
     * (c) free(PCB) is called to release C language memory.
     */
}


