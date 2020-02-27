#include <stdio.h>
#include <string.h>
#include "ram.h"

#define BUFFER 1000
#define MAX_NUM 100

void addToRAM(FILE* p, int* start, int* end) {

     int startPos = *end + 1;
     *start = startPos;

    char buffer[MAX_NUM];
    while (fgets(buffer, MAX_NUM, p) != NULL) {

        if (feof(p)) {break;}
        else if (*start == BUFFER && !feof(p)) {
            printf("%s\n", "Reach maximum storage!");
            fclose(p);
        }

        //TODO: Check validity
        buffer[strcspn(buffer, "\n")] = '\0';
        ram[startPos] = strdup(buffer);
        startPos++;

    }

//    for (int i =*end+1;i<startPos;i++) {
//        printf("%s\n", ram[i]);
//    }

    *end = startPos-1;


    fclose(p);
}