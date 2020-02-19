#include <stdio.h>
#include <stdlib.h>

#include "pcb.h"

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
        printf("%s%d\n", "start is ", pcb->start);
        printf("%s%d\n", "end is ", pcb->end);
        printf("%s\n", "Successfully make PCB");

        //TODO: PC update after quanta finish

        return pcb;
    }
}



