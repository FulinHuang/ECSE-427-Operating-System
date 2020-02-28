#ifndef RAM_H
#define RAM_H
#include <stdio.h>
#include <stdbool.h>

#define BUFFER 1000

bool reachMax;

char *ram[BUFFER];

void addToRAM(FILE *p, int* start, int* end);

bool getRAMStatus();

void setRAMStatus(bool status);
#endif