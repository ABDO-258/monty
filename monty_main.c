#include "monty.h"
#include <stdio.h>

data inform_2;
/**
 * free_stack -  frees stack
 *
 * @head: head of double list
 *
 * Return: void
 */
void free_stack(stack_t **head)
{
	stack_t *current, *temp;

	current = (*head);
	while (current != NULL)
	{
		/*printf("+++%d+++\n", current->n);*/
		temp = current;
		current = current->next;
		free(temp);
	}
	(*head) = NULL;
}

/**
 * isnumber - check if a string is a number
 *
 * @str: the the string to check
 *
 * Return: true if number false if not
 */
bool isnumber(const char str[])
{
	char *endptr;

	strtol(str, &endptr, 10);
	return (*endptr == '\0');
}
/**
 * execute_monty_cmd - execute the rigth commande
 *
 */
void execute_monty_cmd(void)
{
	instruction_t monty_func[] = {
						{"push", monty_push},
						{"pall", monty_pall},
						{"pint", monty_pint},
						{"pop", monty_pop},
						{"swap", monty_swap},
						{"add", monty_add},
						{NULL, NULL},
				};
	int i = 0;

	for (i = 0; monty_func[i].opcode; i++)
	{
		if (strcmp(inform_2.cmdline[0], monty_func[i].opcode) == 0)
		{
			/*printf("_______%s________ \n",inform_2.cmdline[0]);*/
			monty_func[i].f(&inform_2.head, inform_2.line_num);
			/*printf("_______%s________ \n",inform_2.cmdline[0]);*/
			break;
		}
	}
	if (inform_2.cmdline[0][0] == '#')
	{
		return;
	}
	else if (!monty_func[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
		inform_2.line_num, inform_2.cmdline[0]);
		free_stack(&inform_2.head);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
}





/**
 * commande_line - the entry point for Monty Interp
 *
 */
void commande_line(void)
{
	char *token;
	int i, j;
	size_t  n = 100;

	inform_2.line = malloc(sizeof(char) * n);
	if (inform_2.line == NULL)
	{
		fprintf(stderr, "malloc error\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(inform_2.line, n, inform_2.file_ptr))
	{
		inform_2.line_num++;
		if (inform_2.line[0] == '\0' || inform_2.line[0] == '\n')
			continue;
		token = strtok(inform_2.line, " \t\n");
		for (i = 0; token != NULL && i < 10; i++)
		{
			strcpy(inform_2.cmdline[i], token);
			token = strtok(NULL, " \t\n");
		}
		for (j = 0; j != i; j++)
		{
			if (inform_2.cmdline[j][0] == '#')
				continue;
			if (strcmp(inform_2.cmdline[j], "push") == 0 &&
				j + 1 < i && (isnumber(inform_2.cmdline[j + 1]) == false))
			{
				fprintf(stderr, "L%d: usage: push integer\n",
						inform_2.line_num);
				free(inform_2.line);
				fclose(inform_2.file_ptr);
				exit(EXIT_FAILURE);
			}
		}
		/* printf("cmdline = %s in line %d value = %s\n",*/
		/*		inform_2.cmdline[0], inform_2.line_num, inform_2.cmdline[1]);*/
		execute_monty_cmd();
	}
}

/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inform_2.file_ptr = fopen(argv[1], "r");
	if (inform_2.file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	inform_2.line_num = 0;
	commande_line();
	free_stack(&inform_2.head);
	free(inform_2.line);
	fclose(inform_2.file_ptr);
	return (0);
}
