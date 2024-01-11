#include "main.h"

/**
**get_line_size - Get the line size object
**
** Return: int
**/
ssize_t get_line_size(void)
{
	char *line = NULL;

	size_t n = 0;
	size_t linesize = getline(&line, &n, stdin);

	return (linesize);
}


/**
**readline  - readline
**
**Return: char*
**/
char *readline(void)
{

	char *line = NULL;

	size_t n = 0;



	if (getline(&line, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
