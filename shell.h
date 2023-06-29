#ifndef SHELL_H_
#define SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND 100
extern char **environ;

int main(void);
int custom_main(void);
void printPrompt(void);
void removeTrailingNewline(char *string);
void executeCommand(char **args);
void findExecutable(char **args);
void tokenizeString(char *string, char **args);
void runShell(void);
int _strcmp(const char *st1, const char *st2);
int _strlen(const char *s);


#endif
