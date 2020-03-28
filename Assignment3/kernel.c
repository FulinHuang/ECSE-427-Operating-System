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

int start = 0;
int end = -1;

void addToReady(PCB* pcb);
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
    printf("%s\n", "Every cell of the array is initialized to NULL");

    // Delete the old backing store directory and create a new directory
    if (opendir("BackingStore")) {
        system("rmdir BackingStore");
        system("mkdir BackingStore");
        printf("Remove then create backing store\n");
    }
    else if(ENOENT == errno) {  //No Backing Store exists
        system("mkdir BackingStore");
        printf("Make new backing store\n");
    }

}

int main() {
    int error = 0;
    boot();
    error = kernel();

    return error;

}

PCB* myinit(char *filename){

    //TODO: change this

    PCB* pcb = makePCB(start, end);         // Create PCB instance using malloc

    addToReady(pcb);                       // Add PCB to the tail of the Ready Queue

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

//        printf("%s\n", "Print RAM before running quanta");
//        printf("%s%d\n", "start is ", start);
//        printf("%s%d\n", "end is ", end);
//        for (int i = start; i <= end; i++) {
//            printf("%s\n", ram[i]);
//        }


        int pc_value = 0;
        if (pcb != NULL) {
            printf("%s\n", "--- Start New PCB ---");
            cpu.IP = pcb->start+pcb->PC_page*4;
            printf("%s%d\n", "cpu IP is ", cpu.IP);

            // TODO: when IP >= 40


            int quanta = 2;
//            setCPU_IP(pcb);            // copy PC from the PCB into IP of the CPU

            if ((pcb->end - pc_value) == 0) {
//            else if ((pcb->end - pcb->start + 1) - pc_value == 0) {
//            else if (cpu.IP+cpu.offset == pcb->end+1) {
                // program terminate (Remove from Ready Queue)
                printf("%s\n", "---------terminate pcb---------");
                terminatePCB(pcb);
            }

            pc_value = pcb->PC;
            cpu.offset = pcb->PC_offset;

            printf("%s%d\n", "cpu offset ", cpu.offset);
            printf("%s%d\n", "pc_value ", pc_value);
            printf("%s%d\n", "pcb end + 1 ", pcb->end+1);

            // Program needs at least two quanta to finish
//            if (cpu.IP+cpu.offset+quanta <= pcb->end+1) {
            if ((pcb->end + 1 - pc_value) >= quanta) {
                printf("%s\n", "Program needs AT LEAST two quanta to finish");
                run(quanta);

                cpu.offset+=2;

                // Check whether program reach the end of frame or not
                if (cpu.offset == 4){
                    int j = pageFault(pcb);
                    if (j == 0) {
                        terminatePCB(pcb);
                    }
                }
                else {
                    pcb->PC_offset+=2;
                    pcb->PC = cpu.IP + cpu.offset;
                }

                printf("%s%d\n", "pc offset is ", pcb->PC_offset);
                printf("%s%d\n", "cpu offset is ", cpu.offset);
                printf("%s%d\n", "pcb PC is ", pcb->PC);

                addToReady(pcb);
            }
            // program needs less than two quanta to finish
            else if ((pcb->end + 1 - pc_value) < quanta && (pcb->end + 1 - pc_value) != 0) {
//            else if (cpu.IP + cpu.offset + quanta > pcb->end+1 && cpu.IP+cpu.offset != pcb->end+1) {
                printf("%s\n", "Program needs LESS THEN two quanta to finish");
                quanta = 1;
                run(quanta);

                cpu.offset++;

                if (cpu.offset == 4) {
                    int j = pageFault(pcb);
                    setCPU_IP(pcb);           // copy PC from the PCB into IP of the CPU
                    if (j == 0) {
                        terminatePCB(pcb);
                    }
                    pcb->PC_offset = 0;
                }
                else {
                    pcb->PC_offset++;
                    pcb->PC = cpu.IP + cpu.offset;
                }

                printf("%s%d\n", "pc offset is ", pcb->PC_offset);
                printf("%s%d\n", "cpu offset is ", cpu.offset);
                printf("%s%d\n", "cpu IP is ", cpu.IP);
                printf("%s%d\n", "pcb PC is ", pcb->PC);

                // Check whether program is finished or not
                if ((pcb->end - pc_value) == 0) {
//                if (cpu.IP+cpu.offset == pcb->end+1) {
                    // program terminate (Remove from Ready Queue)
                    printf("%s\n", "---------terminate pcb--------");
                    terminatePCB(pcb);
                }
            }

            if ((pcb->end+1 - pc_value) == 0) {
//            else if ((pcb->end - pcb->start + 1) - pc_value == 0) {
//            else if (cpu.IP+cpu.offset == pcb->end+1) {
                // program terminate (Remove from Ready Queue)
                printf("%s\n", "---------terminate pcb---------");
                terminatePCB(pcb);
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
        printf("%s\n", "---------terminate pcb---------");
        PCB* pcb = getPCBfromReady();
        terminatePCB(pcb);
        start = 0;
        end = -1;
    }
}

int pageFault(PCB* pcb) {
    // Check whether Page reaches the end
    printf("%s\n", "Entering page fault!");
    pcb->PC_page++;
    printf("%s%d\n", "PC page is ", pcb->PC_page);

    if (pcb->PC_page > pcb->pages_max) {
        printf("%s\n", "Reach Page Max");
        // Program terminates
        return 0;
    }
    // Move new page to frame
    else {
        // we check to see if the frame for that page exists in the pageTable array
        for (int i = 0; i < 10; i++) {
            printf("%s%d\n", "Page Table is ", pcb->pageTable[i]);
        }

        if (pcb->pageTable[pcb->PC_page] >= 0 && pcb->pageTable[pcb->PC_page] < 10) {

            printf("%s\n", "Frame is valid, program continues...");
            int frameNumber = pcb->pageTable[pcb->PC_page];
            printf("%s%d\n", "Frame number is ", frameNumber);
            pcb->PC = frameNumber*4;  //TODO: Check
            printf("%s%d\n", "pcb PC is now ", pcb->PC);
            pcb->PC_offset = 0;
        }
        // If pageTable[PC_page] is NOT valid then we need to find the page on disk and update
            //the PCB page table and possibly the victim’s page table. Start by (a) finding the
            // page in the backing store, then (b) finding space in RAM (either find a free cell
            // or select a victim), finally (c) update the page tables, (d) update RAM frame with
            // instructions, and do (e) PC=ram[frame] and (f) reset PC_offset to zero.
        else {
            // Find the page in the backing store
            printf("%s\n", "------------------------------------Frame invalid, page fault action ...----------------");
            char file_dir[40];
            //Get the file path
            sprintf(file_dir, "%s%s", "BackingStore/", pcb->filename);
            //Open file
            FILE* file = fopen(file_dir, "r");

            // Finding space in RAM (either find a free cell or select a victim)
            int frameNumber = findFrame();
            printf("%s%d\n", "Frame number is ", frameNumber);
            int victimFrame = 0;
            if(frameNumber == -1) {
                victimFrame = findVictim(pcb);
                printf("%s%d\n", "Frame is a victim Frame", victimFrame);
            }

            // Update the page tables
            updatePageTable(pcb, pcb->PC_page, frameNumber, victimFrame);

            // Update RAM frame with instructions
            loadPage(pcb->PC_page, file, frameNumber);

            // PC=ram[frame] and reset PC_offset to zero.
            if (frameNumber != -1) {
                pcb->PC = frameNumber*4;
            }
            else {
                pcb->PC = victimFrame*4;
            }
            pcb->PC_offset = 0;


        }
        printf("%s\n", "Leaving page fault...");
        return 1;
    }
}