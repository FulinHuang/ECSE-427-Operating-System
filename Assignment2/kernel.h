#ifndef KERNEL_H
#define KERNEL_H
#include "pcb.h"

typedef struct Ready {
    PCB* pcb;
    struct Ready* next;
}Ready;

int myinit(char *filename);

void scheduler();

PCB *getPCBfromReady();

void terminteAll();

#endif