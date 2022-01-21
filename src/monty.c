#include "main.h"

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    static char *buffer;
    size_t bufsize = 32;
    size_t characters;
    FILE *fp;
    int i;

    while(argc--)
    {
        if(argv[1] == NULL || argc > 1)
        {
            printf("USAGE: monty file\n");
            exit(EXIT_FAILURE);
        }
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    characters = getline(&buffer, &bufsize, fp);
    while(characters > 0)
    {
        execute(buffer, stack);
    }

    fclose(fp);
    return (0);
}


void execute(char *buffer[], stack_t *stack)
{
	int ln, n, i;

	instruction_t st[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add}
/**
 *		{"null", NULL}
*/
	};

	for (ln = 1, n = 0; buffer[n + 1]; n++, ln++)
	{
		if (_strcmp("push", buffer[n]))
			push(&stack, ln, pushint(buffer[n], ln));
		else if (_strcmp("nop", buffer[n]))
			;
		else
		{
			i = 0;
			while (!_strcmp(st[i].opcode, "null"))
			{
				if (_strcmp(st[i].opcode, buffer[n]))
				{
					st[i].f(&stack, ln);
					break;
				}
				i++;
			}
			if (_strcmp(st[i].opcode, "null") && !_strcmp(buffer[n], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", ln, buffer[n]);
				if (!nlfind(buffer[n]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	/*free_stack(stack)*/
}