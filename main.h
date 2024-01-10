
#ifndef SIMPLE_SHELL_SHELL_H
#define SIMPLE_SHELL_SHELL_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


#define environ __environ

/**
 * struct built_in - struct for builtin functions
 * @cmd: command
 * @builtin_function: function
 * Return: 0
 */
typedef struct built_in
{
	char *cmd;
	int (*builtin_function)(char **);
} builtin_t;


int loop(void);
char **split(char *line, int *linesize);
int get_line_size(void);
char  *readline();
int execute(char **args);
char *get_path(char *cmd);
int (*get_builtin(char *cmd))(char **args);
int launch(char **args);
int shellExit(char **args);
int shellEnv(char **args);
int shellCd(char **args);
char *shell_read_line();





#endif
