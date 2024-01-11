#include "main.h"


/**
*loop - loop function
*
*Return: int
*/
int  loop(void)
{
	char *line;

	char **tokens;

	size_t linesize;

/*	linesize = get_line_size();*/


	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}


		line = readline();
		if (!line)
		{
			break;
		}

		linesize = strlen(line);

		tokens = split(line, &linesize);

		launch(tokens);

	}

	free(line);
	free(tokens);
	return (0);
}
