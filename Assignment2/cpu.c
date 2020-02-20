#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "cpu.h"
#include "pcb.h"
#include "ram.h"
#include "interpreter.h"

#define BUFFER 1000

bool quitbool = true;

PCB* temp;

void initializeCPU() {
    if (cpu.quanta != 2) {   // if cpu is not yet been initialized
        printf("%s\n", "CPU is null!");
        cpu.IP = 0;
        cpu.IR[0] = '\0';
        cpu.quanta = 2;
        printf("%s\n", "CPU is initialized!");
    }
}

//  It copies the PC from the PCB into the IP of the CPU
void setCPU_IP(PCB *pcb) {
    cpu.IP = pcb->PC;
    temp = pcb;
}

void setQuitProgram(bool value) {
    quitbool = value;
}

bool getQuitProgram() {
    return quitbool;
}

void run(int quanta) {
    cpu.quanta = quanta;

    while (cpu.quanta >= 0 && cpu.IP <= temp->end+1) {
//                printf("%s\n", ram[cpu.IP]);
        if (cpu.quanta == 0 || cpu.IP == temp->end+1) {break;}
        cpu.quanta--;

        strcpy(cpu.IR, ram[cpu.IP]);
        cpu.IP++;
//                printf("end is %d\n", temp->end);
//                printf("quanta is %d\n", cpu.quanta);
        printf("IP is %d\n", cpu.IP);
        setQuitProgram(false);

        interpret(cpu.IR);

    }
// copy quanta line of code from ram[] using IP into IR
// interpreter(ir)
//If program not end:
// PCB PC pointer is updated with IP value
// PCB is placed at tail of Ready queue
// If program end:
// pcb terminate


}