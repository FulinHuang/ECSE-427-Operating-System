#ifndef PCB_H
#define PCB_H

typedef struct PCB{
    int PC;
    int start;
    int end;
    int pageTable[10];
    int PC_page;
    int PC_offset;
    int pages_max;
    //    struct PCB *next;
}PCB;

PCB* makePCB(int start, int end);

void terminatePCB(PCB * pcb);

#endif