#ifndef SHELLMEMORY_H
#define SHELLMEMORY_H

struct MEM {
    char *var;
    char *value;
};

int printValue(char *var, struct MEM *mem);
int setValue(char **words, struct MEM *mem, char * value, char *var);

#endif