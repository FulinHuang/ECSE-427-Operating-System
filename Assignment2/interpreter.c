#include "shellmemory.h"
#include "kernel.h"
#include "cpu.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define BUFFER 1000

bool quitProgram = false;


char **tokenize(char *str)
{
    size_t num_tokens = 1;
    int flag = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (flag == 0 && str[i] == ' ')
        {
            num_tokens = num_tokens + 1;
            flag = 1;
        }
        if (str[i] != ' ')
        {
            flag = 0;
        }
    }
    char **ret_arr =
        (char **)malloc(sizeof(char *) * (num_tokens + 1));

    if (ret_arr == NULL)
    {
        perror("malloc");
        return NULL;
    }
    flag = 0;
    int ignore_flag = 0;
    char *modified_str = (char *)str;
    size_t counter = 0;
    const size_t length_str = strlen(str);
    for (size_t i = 0; i < length_str; i++)
    {
        if (modified_str[i] == '\n' || modified_str[i] == '\r')
            modified_str[i] = ' ';
        if (modified_str[i] == '"')
        {
            ignore_flag = ignore_flag ^ 0x1;
        }
        if (flag == 0 && modified_str[i] != ' ')
        {
            ret_arr[counter] = &(modified_str[i]);
            counter = counter + 1;
            flag = 1;
        }
        if (modified_str[i] == '\\' && modified_str[i + 1] == ' ')
        {
            i++;
            continue;
        }
        if (flag == 1 && modified_str[i] == ' ' && ignore_flag == 0)
        {
            modified_str[i] = '\0';
            flag = 0;
            continue;
        }
    }
    ret_arr[counter] = NULL;

    for (size_t i = 0; i < counter; ++i)
    {
        if (ret_arr[i][0] == '\"' &&
            ret_arr[i][strlen(ret_arr[i] - 1)] == '\"')
        {
            ret_arr[i][strlen(ret_arr[i]) - 1] = '\0';
            ret_arr[i] = ret_arr[i] + 1;
        }
    }

    return ret_arr;
}

int in_file_flag = 0;
int interpret(char *raw_input);

int help()
{
    printf(""
           "COMMAND         DESCRIPTION\n"
           "help            Displays all the commands\n"
           "quit            Exits / terminates the shell with \"Bye!\"\n"
           "set VAR STRING  Assigns a value to shell memory\n"
           "print VAR       Displays the STRING assigned to VAR\n"
           "run SCRIPT.TXT  Executes the file SCRIPT.TXT\n"
           "exec p1 p2 p3   Executes concurrent programs\n"
           "                $ exec prog.txt prog2.txt\n");

    return 0;
}

int quit()
{
    printf("Bye!\n");
    if (in_file_flag == 0 && getQuitProgram())
    {
        shell_memory_destory();
        exit(0);
    }
    else {
        setQuitProgram(true);
    }
    return 0;
}

int runScript(const char *path)
{
    quitProgram = true;
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Script not found.\n");
        return 1;
    }
    int enter_flag_status = in_file_flag;
    in_file_flag = 1;
    while (!feof(file))
    {
        char *line = NULL;
        size_t linecap = 0;
        //if (strcmp(line, "quit") == 0 ||strcmp(line, "quit\n") == 0 || strcmp(line, "quit\r\n") == 0) {
        //    setQuitProgram(false);
        //}

        if (getline(&line, &linecap, file) == -1)
            break;

        int status = interpret(line);
        free(line);
        if (status != 0 && status != 2)
        {
            break;
            return status;
        }
    }
    fclose(file);
    in_file_flag = enter_flag_status;
    return 0;
}

int set(const char *key, const char *value)
{
    int status = shell_memory_set(key, value);
    if (status != 0)
        printf("set: Unable to set shell memory.\n");
    return status;
}

int print(const char *key)
{
    const char *value = shell_memory_get(key);
    if (value == NULL)
    {
        printf("print: Undefined value.\n");
        return 1;
    }
    printf("%s\n", value);
    return 0;
}


int interpret(char *raw_input)
{
    char **tokens = tokenize(raw_input);

    if (tokens[0] == NULL)
        return 0; // empty command

    if (strcmp(tokens[0], "help") == 0)
    {
        if (tokens[1] != NULL)
        {
            printf("help: Malformed command\n");
            free(tokens);
            return 1;
        }
        free(tokens);
        return help();
    }

    if (strcmp(tokens[0], "quit") == 0)
    {
        if (tokens[1] != NULL)
        {
            printf("quit: Malformed command\n");
            free(tokens);
            return 1;
        }
//        if (in_file_flag == 0) {
//            free(raw_input);
//        }
        free(tokens);
        return quit();
    };

    if (strcmp(tokens[0], "set") == 0)
    {

        if (!(tokens[1] != NULL && tokens[2] != NULL && tokens[3] == NULL))
        {
            printf("set: Malformed command\n");
            free(tokens);
            return 2;
        }
        int status = set(tokens[1], tokens[2]);
        free(tokens);
        return status;
    }

    if (strcmp(tokens[0], "print") == 0)
    {
        if (!(tokens[1] != NULL && tokens[2] == NULL))
        {
            printf("print: Malformed command\n");
            free(tokens);
            return 1;
        }
        int status = print(tokens[1]);
        free(tokens);
        return status;
    }

    if (strcmp(tokens[0], "run") == 0)
    {
        if (!(tokens[1] != NULL && tokens[2] == NULL))
        {
            printf("run: Malformed command\n");
            free(tokens);
        }
        int result = runScript(tokens[1]);
        free(tokens);
        return result;
    }

    if (strcmp(tokens[0], "exec") == 0) {
        int i = 1;
        int count = 0;
        while (tokens[i] != NULL) {
            count++;
            i++;
        }
        if (count == 0) {       // no file
            printf("exec: Malformed command\n");
            free(tokens);
            return 1;
        }
        else if (count == 1){   // one file
            int valid;
            valid = myinit(tokens[1]);
            if (valid == 0) {
                scheduler();
                free(tokens);
                return 0;
            } else {
                terminteAll();
                free(tokens);
                return 1;
            }

        }
        else if (count == 2) {
            if ((tokens[1]!= NULL && tokens[2]!= NULL && strcmp(tokens[1], tokens[2]) == 0)) { // same file name
                printf("Error: Script %s already loaded\n", tokens[1]);
                free(tokens);
                return 1;
            }
            else {
                int valid = -1;
                for (int j = 1; j < 3; j++) {
                    valid = myinit(tokens[j]);
                    if (valid == -1){
                        break;
                    }
                }
                if (valid == -1) {
                    terminteAll();
                    free(tokens);
                    return 1;
                } else {
                    scheduler();
                    free(tokens);
                    return 0;
                }
            }
        }
        else if (count == 3) {
            if ((tokens[1]!= NULL && tokens[2]!= NULL && strcmp(tokens[1], tokens[2]) == 0) ||
            (tokens[1] != NULL && tokens[3] != NULL && strcmp(tokens[1], tokens[3]) == 0)) {
                printf("Error: Script %s already loaded\n", tokens[1]);
                free(tokens);
                return 1;
            }
            else if (tokens[2]!=NULL && tokens[3]!= NULL && strcmp(tokens[2], tokens[3]) == 0) {
                printf("Error: Script %s already loaded\n", tokens[2]);
                free(tokens);
                return 1;
            }
            else {
                int valid = -1;
                for (int j = 1; j < 4; j++) {
                    valid = myinit(tokens[j]);
                    if (valid == -1){break; }
                }
                if (valid == -1) {
                    terminteAll();
                    free(tokens);
                    return 1;
                } else {
                    scheduler();
                    free(tokens);
                    return 0;
                }
            }
        }
        else if (count > 3) {
            printf("Cannot load more than three scripts at once!\n");
            free(tokens);
            return 1;
        }

    }

    printf("Unrecognized command \"%s\"\n", tokens[0]);
    free(tokens);
    return 1;
}