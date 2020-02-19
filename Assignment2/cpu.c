#include <stdio.h>
#include "cpu.h"
#include "pcb.h"

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
}


void run(int quanta) {

    // copy quanta line of code from ram[] using IP into IR
    // interpreter(ir)
    //If program not end:
        // PCB PC pointer is updated with IP value
        // PCB is placed at tail of Ready queue
    // If program end:
        // pcb terminate


}