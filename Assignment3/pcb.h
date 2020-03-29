#ifndef PCB_H
#define PCB_H
#include <stdio.h>

typedef struct PCB{
    int PC;
//    int start;
//    int end;
    int pageTable[10];
    int PC_page;
    int PC_offset;
    int pages_max;
    char* filename;
    int pid;

    //    struct PCB *next;
}PCB;

PCB* makePCB();

void terminatePCB(PCB * pcb);

#endif