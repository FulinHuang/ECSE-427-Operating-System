#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

#include "kernel.h"
#include "ram.h"


void boot();

int main() {
    int error = 0;
    boot();
    error = kernel();

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