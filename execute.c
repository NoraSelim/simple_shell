#include "main.h"
/**
*launch - launch execution
*
*@args: args
*Return: int
*/
int launch(char **args)
{

	if (args[0] == NULL)
	{
		return (0);
	}

	if (get_builtin(args[0]))
	{
		return (get_builtin(args[0])(args));
	}

	return (execute(args));
}

/**
*execute - execute function
*
*@args: args
*Return: int
*/
int execute(char **args)
{
	char *cmd = NULL;
	char *location = NULL;
	pid_t pid;
	int status;

	if (args)
	{
		cmd = args[0];
		location = get_path(cmd);

		pid = fork();

		if (pid == 0)
		{
			if (execve(location, args, NULL) == -1)
			{
				free(location);
				perror("error");
				return (0);
			}
			exit(EXIT_FAILURE);
		} else if (pid < 0)
		{
			perror("error");
		}
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);

			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	return (1);
}

/**
 *get_builtin - Get the builtin function
 *
 * @cmd: comand
 * Return: int(*)(char** args)
 */
int (*get_builtin(char *cmd))(char **args)
{
	builtin_t cmds[] = {
			{"cd",   shellCd},
			{"exit", shellExit},
			{"env",  shellEnv},
			{NULL, NULL}
	};
	int i = 0;

	while (cmds[i].cmd != NULL)
	{
		if (strcmp(cmds[i].cmd, cmd) == 0)
		{
			return (cmds[i].builtin_function);
		}
		i++;
	}

	return (NULL);
}
