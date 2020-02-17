#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER 1000
#define MAX_NUM 100

int startPos = 0;

void loadToRam(char* ram, char *fileName, int* start, int* end) {

    *start = startPos;

    FILE *p = fopen(fileName, "rt");    //open file
    if (p == NULL) {
        printf("Script not found.\n");
    }

    char buffer[MAX_NUM];
    while (fgets(buffer, MAX_NUM, p) != NULL) {

        if (feof(p)) {break;}

        //TODO: Check validity
        ram[startPos] = strdup(buffer);
        startPos++;
    }

    *end = startPos;
    fclose(p);
}