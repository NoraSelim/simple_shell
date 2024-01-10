#include "main.h"

/**
 * * get_path - Get the path
 * *
 * * @cmd: command
 * * Return: char*
 **/
char *get_path(char *cmd)
{
	char *path, *path_temp, *token, *file_path;
	int cmd_length, directoryLength;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_temp = strdup(path);
		cmd_length = strlen(cmd);
		token = strtok(path_temp, ":");

		while (token != NULL)
		{
			directoryLength = strlen(token);
			file_path = malloc(cmd_length + directoryLength + 2);
			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_temp);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = strtok(NULL, ":");
			}
		}
		free(path_temp);
		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
