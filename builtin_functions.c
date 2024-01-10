#include "main.h"


/**
*shellExit - exit command
*
*@args: args
*Return: int
*/
int shellExit(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}


/**
*shellEnv - env command
*
* @args: args
*Return: int
*/
int shellEnv(char **args)
{

	int i = 0;

	(void)args;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], (strlen(environ[i]) + 1));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (1);
}

/**
*shellCd - cd command
*
* @args: args
*Return: int
*/
int shellCd(char **args)
{
	if (args[1] == NULL)
	{
		printf("error: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error");
		}
	}
	return (1);
}
