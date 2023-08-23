#include "monty.h"


/**
 * monty_nop - do noting of a doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_nop(stack_t **head, unsigned int line_num)
{
	(void)*head;
	(void)line_num;
}


/**
 * monty_pchar - print the ascii of the top elemeng in the stack
 * by the top element of the stack
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_pchar(stack_t **head, unsigned int line_num)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free_stack(&inform_2.head);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n > 0 && (*head)->n <= 127)
			printf("%c\n", (char)(*head)->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			free_stack(&inform_2.head);
			free(inform_2.line);
			fclose(inform_2.file_ptr);
			exit(EXIT_FAILURE);
		}
	}

}


/**
 * monty_pstr - print the ascii of all elemeng in the stack
 * by the top element of the stack
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_pstr(stack_t **head, unsigned int line_num)
{
	stack_t *current;

	(void)line_num;
	current = (*head);
	while (current != NULL && current->n > 0 &&
			current->n <= 127 && current->n != 0)
	{
		printf("%c", (char)current->n);
		current = current->next;
	}
	printf("\n");
}
