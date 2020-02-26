#ifndef KERNEL_H
#define KERNEL_H
#include "pcb.h"

int myinit(char *filename);

void scheduler();

PCB *getPCBfromReady();

void terminteAll();

#endif