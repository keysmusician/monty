#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
	FILE *bytecode; /* File pointer to the file containing bytecode */
	int chars_read, linecount = 0;	 /* Getline status; linecount*/
	size_t buffsize; /* Line buffer size */
	char *bytecode_path; /* Path of the bytecode file, entered by user */
	char *line = NULL; /* A single line of bytecode */
	char *tokens[] = {NULL, NULL, NULL}; /* First 2 tokens of line, NULL terminated*/

	if (argc != 2) /* Check correct number of arguments */
	{ /* If user did not specify one file, print error and exit */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the bytecode file */
	bytecode_path = argv[1];
	bytecode = fopen(bytecode_path, "r");
	if (!bytecode) /* if file failed to open */
	{
		fprintf(stderr, "Error: Can't open file %s\n", bytecode_path);
		exit(EXIT_FAILURE);
	}

	/* Read a line from the file */
	chars_read = getline(&line, &buffsize, bytecode);
	while (chars_read != -1) /* If line was valid*/
	{
		/* Print line */
		printf("main: L%d: %s", ++linecount, line);
		tokens[0] = strtok(line, " \n\t");
		tokens[1] = strtok(NULL, " \n\t");
		printf("main: Token 1: %s\n", tokens[0]);
		printf("main: Token 2: %s\n\n", tokens[1]);

		/* Continue reading lines until EOF */
		chars_read = getline(&line, &buffsize, bytecode);
	}

	return (0);
}
