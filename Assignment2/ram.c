#include <stdio.h>
#include <string.h>
#include "ram.h"

#define BUFFER 1000
#define MAX_NUM 100

void addToRAM(FILE* p, int* start, int* end) {

    int startPos = 0;
     *start = *end;
     startPos = *start;

    char buffer[MAX_NUM];
    while (fgets(buffer, MAX_NUM, p) != NULL) {

        if (feof(p)) {break;}
        else if (*start == BUFFER && !feof(p)) {
            printf("%s\n", "Reach maximum storage!");
            fclose(p);
        }

        //TODO: Check validity
        buffer[strcspn(buffer, "\n")] = '\0';
        ram[*start] = strdup(buffer);
        startPos++;
        *start = startPos;

    }
    //TODO: When program has finish executing, ram[k] = NULL
    //TODO: Solve problem for RAM: empty one after storing a line

    for (int i =*end;i<startPos;i++) {
        printf("%s\n", ram[i]);
    }

    *end = *start;
    fclose(p);
}