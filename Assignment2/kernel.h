#ifndef KERNEL_H
#define KERNEL_H
#include "pcb.h"

void myinit(char *filename);

void scheduler();

PCB *getPCBfromReady();

#endif