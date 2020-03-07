#ifndef RAM_H
#define RAM_H
#include <stdio.h>
#include <stdbool.h>

// RAM is a global array of 40 strings (modify from 1000 to 40)
#define BUFFER 40

bool reachMax;

char *ram[BUFFER];

void addToRAM(FILE *p, int* start, int* end);

bool getRAMStatus();

void setRAMStatus(bool status);
#endif