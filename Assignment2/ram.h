#ifndef RAM_H
#define RAM_H

#define BUFFER 1000

char *ram[BUFFER];

void loadToRam(char *fileName, int* start, int* end);

#endif