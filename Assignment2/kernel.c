#include <stdlib.h>
#include <stdio.h>

#include "shell.h"
#include "ram.h"
#include "pcb.h"
#include "cpu.h"

void addToReady(PCB* pcb);

int start = 0;
int end = 0;

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

//        PCB* pcb = makePCB(start, end);         // Create PCB instance using malloc

//        addToReady(pcb);                       // Add PCB to the tail of the Ready Queue
    }



}

void addToReady(PCB* pcb) {

}

void scheduler() {

}