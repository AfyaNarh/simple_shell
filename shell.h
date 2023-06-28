#ifndef SHELL_H_
#define SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

#define BUF_SIZE 1024
#define Max_Command 20

int custom_main(void);
void execute_command(char *command, char **env);
void prompt_command(char **av, char **env);
int main(int ac, char **av, char **env);
int _strcmp(const char *st1, const char *st2);
int _strlen(const char *s);
void check_path(const char *command);
void execute_external_command(char **argv, char **env);
int customed_main(void);
void print_environment_variables(char **env);
#endif
