#ifndef CPU_H
#define CPU_H

#include "pcb.h"
#include <stdbool.h>

struct CPU {
    int IP;
    char IR[1000];
    int quanta;
    int offset;
} cpu;

void initializeCPU();

void setCPU_IP(PCB *pcb);

int run(int quanta);

bool getQuitProgram();

void setQuitProgram(bool value);

#endif