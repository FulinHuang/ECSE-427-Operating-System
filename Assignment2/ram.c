#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ram.h"

#define BUFFER 1000
#define MAX_NUM 100


void loadToRam(char *fileName, int* start, int* end) {

     int startPos = 0;
     startPos = *end;

    FILE *p = fopen(fileName, "rt");    //open file
    if (p == NULL) {
        printf("Script not found.\n");
    }

    char buffer[MAX_NUM];
    while (fgets(buffer, MAX_NUM, p) != NULL) {

        if (feof(p)) {break;}
        else if (startPos == BUFFER && !feof(p)) {
            printf("%s\n", "Reach maximum storage!");
            fclose(p);
        }

        //TODO: Check validity
        ram[startPos] = strdup(buffer);
        startPos++;
    }
    //TODO: When program has finish executing, ram[k] = NULL

    *start = startPos;
    *end = startPos;
    fclose(p);
}