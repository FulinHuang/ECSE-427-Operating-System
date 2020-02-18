#ifndef CPU_H
#define CPU_H

typedef struct CPU {
    int IP;
    int IR[1000];
    int quanta;
} CPU;

void run(int quanta);

#endif