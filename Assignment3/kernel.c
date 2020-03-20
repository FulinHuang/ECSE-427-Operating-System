#include <stdio.h>
#include <stdlib.h>

#include "shell.h"
#include "ram.h"
#include "pcb.h"
#include "cpu.h"
#include "kernel.h"
#include "memorymanager.h"

Ready *head = NULL;
Ready *tail = NULL;

int start = 0;
int end = -1;

void addToReady(PCB* pcb);
void pageFault(PCB* pcb);

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
    printf("%s\n", "Every cell of the array is initialized to NULL");

    // Delete the old backing store directory and create a new directory
    //TODO: check
    char *rmcommand  = "rmdir BackingStore";
    system(rmcommand);
    char *mkcommand = "mkdir BackingStore";
    system(mkcommand);

}

int main() {
    int error = 0;
    boot();
    error = kernel();

    return error;

}

int myinit(char *filename){

    //TODO: change this

    PCB* pcb = makePCB(start, end);         // Create PCB instance using malloc
    addToReady(pcb);                       // Add PCB to the tail of the Ready Queue

    return 0;
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

        if (pcb != NULL) {
            int quanta = 2;

            printf("%s%d\n", "Start is now ", start);
            printf("%s%d\n", "End is now ", end);

            // Program needs at least two quanta to finish
            if (cpu.IP+cpu.offset+ quanta <= pcb->end+1) {
                printf("%s\n", "Program needs AT LEAST two quanta to finish");
                run(quanta);
                pcb->PC_offset+=2;
                pcb->PC = cpu.IP + cpu.offset;

                // Check whether program reach the end of frame or not
                if (cpu.offset == 4) {
                    cpu.offset = 0;
                    setCPU_IP(pcb);           // copy PC from the PCB into IP of the CPU
                    pageFault(pcb);
                }

                addToReady(pcb);
            }
            // program needs less than two quanta to finish
            else if (cpu.IP + cpu.offset + quanta > pcb->end+1 && cpu.IP+cpu.offset != pcb->end+1) {
                printf("%s\n", "Program needs LESS THEN two quanta to finish");
                quanta = 1;
                run(quanta);
                pcb->PC_offset++;


                // Check whether program reach the end of frame or not
                if (cpu.offset == 4) {
                    cpu.offset = 0;
                    setCPU_IP(pcb);           // copy PC from the PCB into IP of the CPU
                    pageFault(pcb);
                }

                // Check whether program is finished or not
                if (cpu.IP == pcb->end+1) {
                    // program terminate (Remove from Ready Queue)
                    printf("%s\n", "terminate pcb");
                    terminatePCB(pcb);
                    setRAMStatus(false);
                }
            }
                // Check whether program is finished or not
            else if (cpu.IP == pcb->end+1) {
                // program terminate (Remove from Ready Queue)
                printf("%s\n", "terminate pcb");
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
    //TODO : the file in the backing store is deleted.
    while (head != NULL) {
        printf("%s\n", "terminate pcb");
        PCB* pcb = getPCBfromReady();
        terminatePCB(pcb);
        setRAMStatus(false);
        start = 0;
        end = -1;

    }
}

void pageFault(PCB* pcb) {
    // Check whether Page reaches the end
    printf("%s]n", "Entering page fault!");
    pcb->PC_page++;

    if (pcb->PC_page >= pcb->pages_max) {
        // Program terminates
        terminatePCB(pcb);
        printf("%s\n", "Terminate pcb");
    }
    // Move new page to frame
    else {
        // we check to see if the frame for that page exists in the pageTable array
        if (pcb->pageTable[pcb->PC_page] >= 0 && pcb->pageTable[pcb->PC_page] <= 10) {
            printf("%s\n", "Frame valid");
            int frameNumber = pcb->pageTable[pcb->PC_page];
            pcb->PC = frameNumber*4;  //TODO: Check
            pcb->PC_offset = 0;
        }
        // If pageTable[PC_page] is NOT valid then we need to find the page on disk and update
            //the PCB page table and possibly the victim’s page table. Start by (a) finding the
            // page in the backing store, then (b) finding space in RAM (either find a free cell
            // or select a victim), finally (c) update the page tables, (d) update RAM frame with
            // instructions, and do (e) PC=ram[frame] and (f) reset PC_offset to zero.
        else {
            // Find the page in the backing store
            printf("%s\n", "Frame invalid");
            char file_dir[40];
            //Get the file path
            sprintf(file_dir, "%s%s", "BackingStore/", pcb->filename);
            //Open file
            FILE* file = fopen(file_dir, "r");

            // Finding space in RAM (either find a free cell or select a victim)
            int frameNumber = findFrame();
            int victimFrame = 0;
            if(frameNumber == -1) {
                victimFrame = findVictim(pcb);
            }

            // Update the page tables
            updatePageTable(pcb, pcb->PC_page, frameNumber, victimFrame);

            // Update RAM frame with instructions
            loadPage(pcb->PC_page, file, frameNumber);

            // PC=ram[frame] and reset PC_offset to zero.
            if (frameNumber != -1) {
                pcb->PC = frameNumber*4;  //TODO: Check
            }
            else {
                pcb->PC = victimFrame*4;  //TODO: Check
            }
            pcb->PC_offset = 0;

        }
        printf("%s\n", "Leaving page fault...");


    }
}