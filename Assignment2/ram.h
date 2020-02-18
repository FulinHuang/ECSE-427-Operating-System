#ifndef RAM_H
#define RAM_H
#include <stdio.h>

#define BUFFER 1000

char *ram[BUFFER];

void addToRAM(FILE *p, int* start, int* end);

#endif