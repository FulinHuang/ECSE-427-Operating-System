#include <stdlib.h>
#include <stdio.h>

#include "shell.h"
#include "ram.h"
#include "pcb.h"
#include "cpu.h"

PCB *head = NULL;
PCB *tail = NULL;

void addToReady(PCB* pcb);

int start = 0;
int end = -1;

int main() {
    shellUI();

}

void myinit(char *filename){

    FILE *p = fopen(filename, "rt");
    if (p == NULL) {
        printf("Script not found.\n");
    }
    else {
        addToRAM(p, &start, &end);               // Add source code to cells in RAM

        PCB* pcb = makePCB(start, end);         // Create PCB instance using malloc

        addToReady(pcb);                       // Add PCB to the tail of the Ready Queue
    }

}

void addToReady(PCB* pcb) {

    if (head == NULL) {
        head = pcb;
        tail = pcb;
        printf("%s\n", "Successfully add to Queue");
    }
    else {
        tail->next = pcb;   // update linked list
        tail = pcb;
        printf("%s\n", "Successfully add to Queue");
    }
}

PCB* getPCBfromReady(){
    PCB* pcb = NULL;
    if (head != NULL) {
        pcb = head;
        head = head->next;
        if (head == NULL) {     // If nothing left in the Ready Queue, assign head and tail as NULL
            tail = NULL;
        }
        pcb->next = NULL;
    }

    return pcb;
}

void scheduler() {

    initializeCPU();                // initialize cpu if it is not yet been initialized

    PCB* pcb = getPCBfromReady();  // get first PCB from the ready queue

    if (pcb != NULL) {
        setCPU_IP(pcb);            // copy PC from the PCB into IP of the CPU
        run(cpu.quanta);           //
    }


    /**
     *  a. It checks to see if the CPU is available. This means that the quanta is finished or nothing
     *  is currently assigned to the CPU
        b. It copies the PC from the PCB into the IP of the CPU
        c. It calls the run(quanta) function within cpu.c to run the script by copying quanta
        lines of code from ram[] using IP into the IR, which then calls: interpreter(IR)
        d. This executes quanta instructions from the script or until the script file is at end.
        e. If the program is not at the end, then the PCB PC pointer is updated with the IP
        value and the PCB is placed at the tail of the ready queue.
        f. If the program is at the end, then the PCB terminates (as described previously /
        above)
     */

}