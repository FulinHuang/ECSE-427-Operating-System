#include "interpreter.h"
#include "shellmemory.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

char prompt[100] = "$ \0";



int shellUI()
{
    printf("Kernel 1.0 loaded!\n"
           "Welcome to the Irene's shell!\n"
           "Shell version 3.0 Updated March 2020\n");

    shell_memory_initialize();

//    while (!feof(stdin))
//    {
//        printf("$ ");
//        fflush(stdout);
//
//        char *line = NULL;
//        size_t linecap = 0;
//        if (getline(&line, &linecap, stdin) == -1)
//            break;
//
//        (void)interpret(line);
//        free(line);
//    }

    bool cond  = true;
    while (1) {

        char *line = NULL;
        size_t linecap = 0;
        if (cond) {
            printf("%s", prompt);
        }

        getline(&line, &linecap, stdin);
        if (!isatty(fileno(stdin)) && !feof(stdin)){
            printf("%s", prompt);
            printf("%s",line);
            cond = false;
        }

        (void)interpret(line);
        free(line);

    }

    shell_memory_destory();

    return 0;
}