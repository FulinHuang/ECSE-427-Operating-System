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

    for (int i = 0; i < 10; i++) {
        int frameNumber = pcb->pageTable[i];
        if (frameNumber != -999) {
            for (int j = 0; j < 4; j++) {
                ram[frameNumber*4 + j] = NULL;
            }
        }

    }
    for (int i = 0; i < 40; i++){
        printf("%s\n", ram[i]);
    }


    free(pcb);

//    char* filename = pcb->filename;
    int fileNumber = pcb->pid;
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


