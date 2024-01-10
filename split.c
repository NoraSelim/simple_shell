nclude "main.h"

/**
 * *split - split line
 * *@line: line
 * *@linesize: lonesize
 * * Return: char**
 * */
char **split(char *line, int *linesize)
{
	const char *d = " \n\t";
	char *copy, *token;
	char **args;
	int num_tokens = 0;
	int i;

	copy = malloc(sizeof(char) * (*linesize + 1));
	if (copy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(copy, line);
	token = strtok(copy, d);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, d);
	}
	args = malloc(sizeof(char *) * (num_tokens + 1));
	if (args == NULL)
	{
		free(copy);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, d);
	for (i = 0; i < num_tokens; i++)
	{
		args[i] = token;
		token = strtok(NULL, d);
	}
	args[i] = NULL;
	free(copy);
	return (args);
}

