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

	ssize_t linesize;

	linesize = get_line_size();


	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}


		line = shell_read_line();
		if (!line)
		{
			break;
		}


		tokens = split(line, &linesize);

		launch(tokens);

	}

	free(line);
	free(tokens);
}
