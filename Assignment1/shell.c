#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "interpreter.h"
#include "shellmemory.h"

#define MAX_INPUT 1000
#define MAX_MEM 1000


char welcome[34] = "Welcome to the Irene Huang shell!\n";
char version[35] = "Version 1.0 Created January 2020\n";
char prompt[100] = "$ \0";
int errorCode;
char userInput[MAX_INPUT];
int parseInput(char *ui, char str);
struct MEM* mem;

int main() {

    mem = malloc(sizeof(struct MEM) * MAX_MEM);
    printf("%s", welcome);  //display welcome message
    printf("%s", version);

    while (1) {

        printf("%s", prompt);
        fgets(userInput, MAX_INPUT - 1, stdin);

        if (!isatty(fileno(stdin))){
            printf("%s",userInput);
        }

        char str = userInput[MAX_INPUT-1];

        errorCode = parseInput(userInput, str);

        if (errorCode == 1) {
            printf("%s", "User input is more than 1000!\n");
        }
        else if (errorCode == -1) {
            exit(99);
        }
        else if (errorCode == 2) {
            printf("%s", "Unknown command\n");
        }
        else if (errorCode == 3) {
            printf("%s", "Script not found\n");
        }
        else if (errorCode == 4) {
            printf("%s", "Memory size has exceeded maximum capacity\n");
        }
        else if (errorCode == 5) {
            printf("%s", "Variable does not exist\n");
        }


    }

}

int parseInput (char *ui, char str) {
    int size = 300;
    char *words[size];
    char tmp[200];

    int a;
    int b;
    int w = 0;
    for (a = 0; ui[a] == ' ' && a < size; a++);  //skip white spaces

    /* Does not deal with empty spaces between the command*/
    while (ui[a] != '\0' && a < size) {
        for (b = 0; ui[a] != '\0' && ui[a] != ' ' && ui[a] != '\r' && ui[a] != '\t' && ui[a] != '\n' && a < size; a++, b++) {
            tmp[b] = ui[a];
        }
        tmp[b] = '\0';

        words[w] = strdup(tmp);
        a++; w++;
    }

    /*  Deal with empty spaces */
    /*
    char *token = strtok(ui, " ");
    while (ui[a] != '\0' && a < size && token) {

        //remove \t before a string
        int j = 0;
        bool valid = false;
        for (int k = 0; k < strlen(token); k++) {
            if(token[k] != '\t' && token[k] != '\n' && token[k] != '\r' && token[k] != '\0' && token[k] != ' ') {
                valid = true;
                token[j++] = token[k];
            }
        }
        if (valid) {
            token[j] = '\0';
        }


        words[w] = strdup(token);
        w++;
        token = strtok(NULL, " ");

    }*/


    for (w = w; w < size - 1; w++) {
        words[w] = NULL;
    }

    return interpreter(words, str, mem);

}



