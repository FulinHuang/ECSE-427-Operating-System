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

        return pcb;
    }
}

void terminatePCB(PCB* pcb){

    for (int i = 0; i < 10; i++) {
        int frameNumber = pcb->pageTable[i];
        if (frameNumber != -999) {
            for (int j = 0; j < 4; j++) {
                ram[frameNumber*4 + j] = NULL;
            }
        }
    }

    // Remove from pcb table
    for (int i = 0; i < 10; i++) {
        if (pcbTable[i] == pcb) {
            pcbTable[i] = NULL;
        }
    }

    int fileNumber = pcb->pid;
    pcb = NULL;

    free(pcb);
    char cpCommand[50];
    sprintf(cpCommand, "rm %s%d", "BackingStore/", fileNumber);
    system(cpCommand);


    /**
     * (a) the ram[] cells are assigned NULL for all instructions,
     * (b) the PCB is removed from the Ready Queue, and
     * (c) free(PCB) is called to release C language memory.
     */
}


