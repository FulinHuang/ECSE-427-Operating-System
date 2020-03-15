#ifndef KERNEL_H
#define KERNEL_H
#include "pcb.h"

typedef struct Ready {
    PCB* pcb;
    struct Ready* next;
}Ready;

// start and tail were moved from kernel.c to kernel.h
extern int start;
extern int end;

// head and tail were moved from kernel.c to kernel.h
Ready *head = NULL;
Ready *tail = NULL;

int myinit(char *filename);

void scheduler();

PCB *getPCBfromReady();

void terminteAll();

#endif