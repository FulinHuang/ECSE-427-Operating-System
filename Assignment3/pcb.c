#include <stdio.h>
#include <stdlib.h>

#include "pcb.h"
#include "ram.h"

/*Ready Queue is FIFO and RR*/
PCB* makePCB(int start, int end) {  //creat node

    PCB *pcb = (PCB *) malloc(sizeof(PCB));
    if (pcb == NULL) {
        return NULL;
    }
    else {
        pcb->PC = start;
        pcb->start = start;
        pcb->end = end;

        return pcb;
    }
}

void terminatePCB(PCB* pcb){

    for (int i = pcb->start; i <= pcb->end; i++){
        ram[i] = NULL;
    }
    free(pcb);


    /**
     * (a) the ram[] cells are assigned NULL for all instructions,
     * (b) the PCB is removed from the Ready Queue, and
     * (c) free(PCB) is called to release C language memory.
     */
}


