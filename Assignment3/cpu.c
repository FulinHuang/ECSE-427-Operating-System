#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "cpu.h"
#include "pcb.h"
#include "ram.h"
#include "interpreter.h"


bool quitbool = true;

void initializeCPU() {
    if (cpu.quanta != 2) {   // if cpu is not yet been initialized
        cpu.IP = 0;
        cpu.IR[0] = '\0';
        cpu.quanta = 2;
        cpu.offset = 0;
    }
}

//  It copies the PC from the PCB into the IP of the CPU
void setCPU_IP(PCB *pcb) {
    cpu.IP = pcb->PC;
}

void setQuitProgram(bool value) {
    quitbool = value;
}

bool getQuitProgram() {
    return quitbool;
}

void run(int quanta) {
    cpu.quanta = quanta;
    printf("%s\n", "Running quanta...");
    int offset = cpu.offset;

    while (cpu.quanta >= 0 && offset < 4) {

        if (cpu.quanta == 0 || offset == 4) {break;}
        cpu.quanta--;

        printf("%s%d\n", "Read from position ", cpu.IP+offset);
        strcpy(cpu.IR, ram[cpu.IP+offset]);
        printf("%s\n", ram[cpu.IP+offset]);
//        cpu.IP++;
        offset++;

        setQuitProgram(false);

        interpret(cpu.IR);

    }


}