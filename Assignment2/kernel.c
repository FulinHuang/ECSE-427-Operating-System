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

int myinit(char *filename){

    FILE *p = fopen(filename, "rt");
    if (p == NULL) {
        printf("Script not found\n");
        return -1;
    }
    else {
        addToRAM(p, &start, &end);               // Add source code to cells in RAM

        PCB* pcb = makePCB(start, end);         // Create PCB instance using malloc

        addToReady(pcb);                       // Add PCB to the tail of the Ready Queue

        return 0;
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
            tail = NULL;            //TODO: terminate program?
        }
        pcb->next = NULL;
    }

    return pcb;
}


void scheduler() {

    initializeCPU();                // initialize cpu if it is not yet been initialized

    while (head != NULL) {
        PCB* pcb = getPCBfromReady();  // get first PCB from the ready queue

        if (pcb != NULL) {
            setCPU_IP(pcb);            // copy PC from the PCB into IP of the CPU
            int quanta = 2;

            printf("end is % d\n", pcb->end+1);

            if (cpu.IP+quanta > pcb ->end+1 && cpu.IP != pcb->end+1) {          // program needs less than two quanta to finish
                printf("%s\n", "less than two quanta!");
                quanta = 1;
                run(quanta);
                if (cpu.IP == pcb->end+1) {        // program is finished
                    // program terminate (Remove from Ready Queue)
                    printf("%s\n", "Trying to terminate PCB ...");
                    terminatePCB(pcb);
                }
            }
            else if (cpu.IP+2 <= pcb->end+1) {       // program needs at least two quantas to finish
                printf("%s\n", "more than two quanta!");
                run(quanta);
                pcb->PC = cpu.IP;  // update PCB PC  pointer
                addToReady(pcb);
                // pcb place at the tail of the ready queue
            }
            else if (cpu.IP == pcb->end+1) {        // program is finished
                // program terminate (Remove from Ready Queue)
                printf("%s\n", "Trying to terminate PCB ...");
                terminatePCB(pcb);
            }

            //TODO :WHERe to check if all programs are terminate ?
        }

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

// This method will be called if one of the script has load error, then all other processes that has been added to the ready queue
// will be removed. All instructions in RAM will be removed as well.
void terminteAll() {
    while (head != NULL) {
        PCB* pcb = getPCBfromReady();
        terminatePCB(pcb);
    }


}