#include "monty.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv __attribute__((unused)))
{
	FILE *bytecode; /* File pointer to the file containing bytecode */
	int chars_read;	 /* Getline status */
	size_t buffsize; /* Line buffer size */
	char *bytecode_path; /* Path of the bytecode file, entered by user */
	char *line = NULL; /* A single line of bytecode */

	if (argc != 2) /* Check correct number of arguments */
	{ /* If user did not specify one file, print error and exit */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the bytecode file */
	bytecode_path = argv[1];
	bytecode = fopen(bytecode_path, "r");
	if (!bytecode) /* File failed to open */
	{
		fprintf(stderr, "Error: Can't open file %s\n", bytecode_path);
		exit(EXIT_FAILURE);
	}

	/* Read a line from the file */
	chars_read = getline(&line, &buffsize, bytecode);
	if (chars_read == -1) /* do what?? */
	{
		exit(EXIT_FAILURE);
	}

	printf("%s\n", line);

	return (0);
}
