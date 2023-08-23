#include "monty.h"
/**
 * monty_push - add a new element to the doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_push(stack_t **head, unsigned int line_num)
{
	stack_t *new_node;/*Creat a new node*/
	(void)line_num;

	/*printf("++++start monty push +++++\n");*/
	new_node = malloc(sizeof(stack_t));/*allocate memory for the new node*/
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(inform_2.cmdline[1]); /*put data in the node*/
	new_node->prev = NULL;
	new_node->next = (*head);/*make next of new node head*/

	if (*head != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
	/*printf("++++ end monty push +++++\n");*/
}


/**
 * monty_pall - print the contnet of a doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_pall(stack_t **head, unsigned int line_num)
{
	stack_t *current;
	(void)line_num;
	if ((*head) == NULL)
		return;

	/*printf("++++ start pall push +++++\n");*/
	current = (*head);
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	/*printf("++++ end pall push +++++\n");*/
}

/**
 * monty_pint - prints the value at the top of a doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */
void monty_pint(stack_t **head, unsigned int line_num)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);

}


/**
 * monty_pop - delete the  first element of a doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */
void monty_pop(stack_t **head, unsigned int line_num)
{
	stack_t *delpop;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	delpop = (*head);
	if ((*head)->next == NULL)
	{
		free(*head);
		(*head) = NULL;
	}
	else
	{
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(delpop);
	}

}

/**
 * monty_swap - swap the two first element of a doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_swap(stack_t **head, unsigned int line_num)
{
	stack_t *temp1;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free_stack(&inform_2.head);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp1 = (*head);
		temp1->prev = temp1->next;
		if ((*head)->next->next == NULL)
			temp1->next = NULL;
		else
		{
			temp1->next = temp1->next->next;
			temp1->next->prev = *head;
		}
		(*head) = temp1->prev;
		(*head)->prev = NULL;
		(*head)->next = temp1;

	}

}
