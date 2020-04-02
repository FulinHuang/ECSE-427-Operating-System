#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

#include "shell.h"
#include "ram.h"
#include "pcb.h"
#include "cpu.h"
#include "kernel.h"
#include "memorymanager.h"

Ready *head = NULL;
Ready *tail = NULL;

int pageFault(PCB* pcb);

int kernel() {
    int error = 0;
    shellUI();

    return error;
}

void boot() {

    // Initialize every cell of the array to NULL
    for (int i = 0; i < BUFFER; i++) {
        ram[i] = NULL;
    }

    // Delete the old backing store directory and create a new directory
    if (opendir("BackingStore")) {
        system("rmdir BackingStore");
        system("mkdir BackingStore");
    }
    else if(ENOENT == errno) {  //No Backing Store exists
        system("mkdir BackingStore");
    }

}

int main() {
    int error = 0;
    boot();
    error = kernel();

    return error;

}

PCB* myinit(char *filename){

    PCB* pcb = makePCB();         // Create PCB instance using malloc

    addToReady(pcb);             // Add PCB to the tail of the Ready Queue

    return pcb;
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

        PCB *pcb = getPCBfromReady();  // get first PCB from the ready queue
        int status = 0;

//        int pc_value = 0;
        if (pcb != NULL) {

            int value = pcb->PC/4;
            int count = 0;
            for (int i = 0; i < 10; i++) {
                if (pcb->pageTable[i] != value) {
                    count++;
                }
                else {
                    continue;
                }
            }
            if (count == 10) {
                int victimFrame = findVictim(pcb);
                char file_dir[40];
                sprintf(file_dir, "%s%d", "BackingStore/", pcb->pid);
                FILE* file = fopen(file_dir, "r");

                loadPage(pcb->PC_page, file, victimFrame);
                updatePageTable(pcb, pcb->PC_page, -1, victimFrame);
                pcb->PC = victimFrame*4;

            }
            else {
                cpu.IP = (pcb->PC/4)*4;
                int quanta = 2;
                cpu.offset = pcb->PC_offset;

                // Program needs at least two quanta to finish
                if (4 - cpu.offset >= 1 && pcb->PC_page < pcb->pages_max) {

                    status = run(quanta);

                    // Check whether program reach the end of frame or not
                    if (cpu.offset == 4){
                        int j = pageFault(pcb);
                        if (j == 0) {
                            terminatePCB(pcb);
                            continue;
                        }
                    }
                    else {
                        pcb->PC_offset = cpu.offset;
                        pcb->PC = cpu.IP + cpu.offset;
                    }
                }
            }
            if(status == -1) {
                terminatePCB(pcb);
            }
            else {
                if (pcb->PC_page == pcb->pages_max) {

                    terminatePCB(pcb);
                }
                addToReady(pcb);
            }

        }
    }
}

// This method will be called if one of the script has load error, then all other processes that has been added to the ready queue
// will be removed. All instructions in RAM will be removed as well.
void terminteAll() {
    while (head != NULL) {
        PCB* pcb = getPCBfromReady();
        terminatePCB(pcb);
    }
}

int pageFault(PCB* pcb) {
    // Check whether Page reaches the end
    pcb->PC_page++;

    if (pcb->PC_page >= pcb->pages_max) {

        return 0;
    }
    // Move new page to frame
    else {
        // we check to see if the frame for that page exists in the pageTable array
        if (pcb->pageTable[pcb->PC_page] >= 0 && pcb->pageTable[pcb->PC_page] < 10) {
            int frameNumber = pcb->pageTable[pcb->PC_page];
            pcb->PC = frameNumber*4;
            pcb->PC_offset = 0;
        }

        else {
            // Find the page in the backing store
            char file_dir[40];

            //Get the file path
            sprintf(file_dir, "%s%d", "BackingStore/", pcb->pid);

            //Open file
            FILE* file = fopen(file_dir, "r");

            // Finding space in RAM (either find a free cell or select a victim)
            int frameNumber = findFrame();
            int victimFrame = 0;
            if(frameNumber == -1) {
                victimFrame = findVictim(pcb);
            }

            // Update RAM frame with instruction
            if (frameNumber == -1) {
                loadPage(pcb->PC_page, file, victimFrame);
            }
            else {
                loadPage(pcb->PC_page, file, frameNumber);
            }

            // Update the page tables
            updatePageTable(pcb, pcb->PC_page, frameNumber, victimFrame);

            // PC=ram[frame] and reset PC_offset to zero.
            if (frameNumber != -1) {
                pcb->PC = frameNumber*4;
            }
            else {
                pcb->PC = victimFrame*4;
            }
            pcb->PC_offset = 0;


        }
        return 1;
    }
}