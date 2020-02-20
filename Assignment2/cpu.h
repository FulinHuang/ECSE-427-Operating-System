#ifndef CPU_H
#define CPU_H

#include "pcb.h"
#include <stdbool.h>

struct CPU {
    int IP;
    char IR[1000];
    int quanta;
} cpu;

void initializeCPU();

void setCPU_IP(PCB *pcb);

void run(int quanta);

bool getQuitProgram();

void setQuitProgram(bool value);

#endif