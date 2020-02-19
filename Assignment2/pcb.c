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
        pcb->next = NULL;
//        printf("%s%d\n", "start is ", pcb->start);
//        printf("%s%d\n", "end is ", pcb->end);
//        printf("%s\n", "Successfully make PCB");

        //TODO: PC update after quanta finish

        return pcb;
    }
}

void terminatePCB(PCB* pcb){

    for (int i = pcb->start; i <= pcb->end; i++){
        ram[i] = NULL;
    }
    printf("%s\n", "PCB terminate!");
    free(pcb);


    /**
     * (a) the ram[] cells are assigned NULL for all instructions,
     * (b) the PCB is removed from the Ready Queue, and
     * (c) free(PCB) is called to release C language memory.
     */
}


