#include <stdio.h>
#include <stdlib.h>

#include "shell.h"
#include "ram.h"
#include "pcb.h"
#include "cpu.h"
#include "kernel.h"

Ready *head = NULL;
Ready *tail = NULL;

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
    else if (getRAMStatus()) {  // RAM is full
        return -1;
    }

    else {
        addToRAM(p, &start, &end);               // Add source code to cells in RAM

        if (!getRAMStatus()) {                      // if RAM is not full
            PCB* pcb = makePCB(start, end);         // Create PCB instance using malloc

            addToReady(pcb);                       // Add PCB to the tail of the Ready Queue
        } else {
            //Remove all instructions from RAM
            for (int i = 0; i <= BUFFER; i++){
                ram[i] = NULL;
            }
            setRAMStatus(false);
            start = 0;
            end = -1;
            return -1;
        }
        return 0;
    }

}

void addToReady(PCB* pcb) {
    Ready *ready = (Ready*) malloc(sizeof(Ready));
    //create a new node
    ready->pcb = pcb;
    ready->next = NULL;

    if (head == NULL) {
        head = ready;
        tail = ready;
    }
    else {
        tail->next = ready;   // update linked list
        tail = ready;
    }
}

PCB* getPCBfromReady(){
    PCB* pcb = NULL;
    if (head != NULL) {
        pcb = head->pcb;
        head = head->next;
        if (head == NULL) {     // If nothing left in the Ready Queue, assign head and tail as NULL
            tail = NULL;
        }
    }

    return pcb;
}


void scheduler() {

    initializeCPU();                // initialize cpu if it is not yet been initialized

    while (head != NULL) {

        if (getRAMStatus() == true) {  // If RAM is full, we do not execute any program. Delete everything from RAM
            terminteAll();
        }
        PCB* pcb = getPCBfromReady();  // get first PCB from the ready queue

        if (pcb != NULL) {
            setCPU_IP(pcb);            // copy PC from the PCB into IP of the CPU
            int quanta = 2;

            if (cpu.IP+quanta > pcb ->end+1 && cpu.IP != pcb->end+1) {          // program needs less than two quanta to finish
                quanta = 1;
                run(quanta);

                if (cpu.IP == pcb->end+1) {        // program is finished
                    // program terminate (Remove from Ready Queue)
                    terminatePCB(pcb);
                    setRAMStatus(false);
                }
            }
            else if (cpu.IP+2 <= pcb->end+1) {       // program needs at least two quantas to finish
                run(quanta);
                pcb->PC = cpu.IP;  // update PCB PC  pointer
                addToReady(pcb);
            }
            else if (cpu.IP == pcb->end+1) {        // program is finished
                // program terminate (Remove from Ready Queue)
                terminatePCB(pcb);
                setRAMStatus(false);
            }
        }

    }
    start = 0;
    end = -1;
}

// This method will be called if one of the script has load error, then all other processes that has been added to the ready queue
// will be removed. All instructions in RAM will be removed as well.
void terminteAll() {
    while (head != NULL) {
        PCB* pcb = getPCBfromReady();
        terminatePCB(pcb);
        setRAMStatus(false);
        start = 0;
        end = -1;

    }

}