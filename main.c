#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - main loop for monty bytecode interpreter
 * @argc: command line argument count
 * @argv: command line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *bytecode; /* File pointer to the file containing bytecode */
	int chars_read, linecount = 0;	 /* Getline status; linecount*/
	size_t buffsize; /* Line buffer size */
	char *bytecode_path; /* Path of the bytecode file, entered by user */
	char *line = NULL; /* A single line of bytecode */
	char *tokens[] = {NULL, NULL, NULL}; /* First 2 tokens of line & NULL */

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
	/* Save pointers to free later */
	free_all(&line, &bytecode);
	/* Read a line from the file */
	chars_read = getline(&line, &buffsize, bytecode);
	while (chars_read != -1) /* If line was valid*/
	{
		/* Print line */
		/* printf("main: L%d: %s", ++linecount, line); */
		tokens[0] = strtok(line, " \n\t");
		tokens[1] = strtok(NULL, " \n\t");
		/* printf("main: Token 1: [%s] Token 2: [%s]\n", tokens[0], tokens[1]); */

		get_function(tokens, ++linecount);

		/* Continue reading lines until EOF */
		chars_read = getline(&line, &buffsize, bytecode);
	}
	free_all(NULL, NULL);
	return (EXIT_SUCCESS);
}

/**
 * free_all - clean up before exiting
 * @buffer_address: line buffer from getline() (for initilization)
 * @bytecode_file: open bytecode file (for initilization)
 *
 * Description: If any argument is given, it is saved to a static variable.
 * If all arguments are NULL, free_all() will close the open bytecode file,
 * free the getline() buffer, and free all nodes in the stack if any.
 */
void free_all(char **buffer_address, FILE **bytecode_file)
{
	static char **line;
	static FILE **bytecode;

	if (buffer_address || bytecode_file)
	{
		line = buffer_address ? buffer_address : line;
		bytecode = bytecode_file ? bytecode_file : bytecode;
		return;
	}

#if DEBUG
	printf("free_all: closing bytecode file @ %p\n", (void *)bytecode);
	printf("free_all: freeing buffer @ %p\n", (void *)line);
#endif
	fclose(*bytecode);
	free(*line);
	free_stack(stack);
}
