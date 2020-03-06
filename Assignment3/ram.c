#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ram.h"

#define MAX_NUM 100


void addToRAM(FILE* p, int* start, int* end) {


    reachMax = false;

    int startPos = *end + 1;
    *start = startPos;

    char buffer[MAX_NUM];
    while (fgets(buffer, MAX_NUM, p) != NULL) {

        if (feof(p)) {break;}
        else if (startPos == BUFFER && !feof(p)) {
            printf("%s\n", "Reach maximum storage!");
            fclose(p);
            reachMax = true;
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        ram[startPos] = strdup(buffer);
        startPos++;

    }

    *end = startPos-1;


    fclose(p);
}

void setRAMStatus(bool status) {
    reachMax = status;
}

bool getRAMStatus() {
    return reachMax;
}