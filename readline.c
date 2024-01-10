#include "main.h"

/**
 * *get_line_size - Get the line size object
 * *
 * * Return: int
 * */
int get_line_size(void)
{
	char *line = NULL;

	ssize_t n = 0;
	ssize_t linesize = getline(&line, &n, stdin);

	return (linesize);
}


/**
 * *readline  - readline
 * *
 * *Return: char*
 * */
char *readline(void)
{

	char *line = NULL;

	ssize_t n = 0;



	if (getline(&line, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
		free(line);
		return (NULL);
	}
	return (line);
}#include "main.h"

/**
 * *get_line_size - Get the line size object
 * *
 * * Return: int
 * */
int get_line_size(void)
{
	char *line = NULL;

	ssize_t n = 0;
	ssize_t linesize = getline(&line, &n, stdin);

	return (linesize);
}


/**
 * *readline  - readline
 * *
 * *Return: char*
 * */
char *readline(void)
{

	char *line = NULL;

	ssize_t n = 0;



	if (getline(&line, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
		free(line);
		return (NULL);
	}
	return (line);
}
