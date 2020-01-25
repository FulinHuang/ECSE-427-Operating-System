#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shellmemory.h"
#include <stdbool.h>

#define MAX_MEM 1000

int errorCode;

int setValue(char **words, struct MEM* mem, char *value, char *var) {

    bool exist = false;
    int n = 0;
    for (int i = 0; i < MAX_MEM && mem[i].var != NULL; i++) {  // find variable location
        if (strcmp(mem[i].var, var) == 0) {
            exist = true;
            n = i;
        }
    }

    if (exist == true) {  //var is already exist
        mem[n].value = value;
    }
    else {
        int i;
        for (i = 0; mem[i].var != NULL; i++);
        if (i >= MAX_MEM) {
            errorCode = 4;
            return errorCode;
        }
        mem[i].var = strdup(var);
        mem[i].value = strdup(value);
        errorCode = 0;
    }
//    for (int z = 0; z < MAX_MEM; z ++) {
//        printf("%s ", mem[z].var);
//        printf("%s\n", mem[z].value);
//    }

    return errorCode;
}


int printValue(char *var, struct MEM* mem) {
//        for (int z = 0; z < MAX_MEM; z ++) {
//        printf("%s ", mem[z].var);
//        printf("%s\n", mem[z].value);
//        }

    int n = 0;
    bool exist = false;
    for (int i = 0; i < MAX_MEM && mem[i].var != NULL; i++) {  // find variable location
        if (strcmp(mem[i].var, var) == 0) {
            exist = true;
            n = i;
        }
    }

    if (exist) { //if the value is available, then print the value
        printf("%s\n", mem[n].value);
        errorCode = 0;
    }
    else {  //if the value is not available, return the error code
        errorCode = 5;
    }

    //return error code
    return errorCode;

}

