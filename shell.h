#ifndef SHELL_H_
#define SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

int custom_main(void);
void execute_command(char *command, char **env);
void prompt_command(char **av, char **env);
int main(int ac, char **av, char **env);
int _strcmp(const char *st1, const char *st2);
int _strlen(const char *s);
#endif
