#include <stdio.h>
#include <stdlib.h>

#include "pcb.h"
#include "ram.h"
#include "kernel.h"

/*Ready Queue is FIFO and RR*/
PCB* makePCB(int start, int end) {  //creat node
    printf("%s%d\n", "PCB start is ", start);
    printf("%s%d\n", "PCB end is ", end);

    PCB *pcb = (PCB *) malloc(sizeof(PCB));
    if (pcb == NULL) {
        return NULL;
    }
    else {
//        pcb->PC = start;
        pcb->start = 0;
        pcb->end = 0;

        return pcb;
    }
}

void terminatePCB(PCB* pcb){

    for (int i = pcb->start; i <= pcb->end; i++){
        ram[i] = NULL;
    }
    free(pcb);

    char* filename = pcb->filename;
    printf("%s%s\n", "file name is ", pcb->filename);
    char cpCommand[50];
    sprintf(cpCommand, "rm %s%s", "BackingStore/", filename);
    system(cpCommand);
    printf("File REMOVED\n");


    /**
     * (a) the ram[] cells are assigned NULL for all instructions,
     * (b) the PCB is removed from the Ready Queue, and
     * (c) free(PCB) is called to release C language memory.
     */
}


