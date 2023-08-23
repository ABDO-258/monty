#include "monty.h"

/**
 * monty_add - add the two first element of a doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_add(stack_t **head, unsigned int line_num)
{
	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_stack(&inform_2.head);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n = (*head)->next->n + (*head)->n;
		monty_pop(&inform_2.head, inform_2.line_num);
	}

}

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
	return;
}
