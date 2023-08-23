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
 * monty_sub - add the two first element of a doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_sub(stack_t **head, unsigned int line_num)
{
	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_stack(&inform_2.head);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n = (*head)->next->n - (*head)->n;
		monty_pop(&inform_2.head, inform_2.line_num);
	}

}


/**
 * monty_div - divides the second element of the stack
 * by the top element of the stack
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_div(stack_t **head, unsigned int line_num)
{
	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_stack(&inform_2.head);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_num);
			free_stack(&inform_2.head);
			free(inform_2.line);
			fclose(inform_2.file_ptr);
			exit(EXIT_FAILURE);

		}
		(*head)->next->n = (*head)->next->n / (*head)->n;
		monty_pop(&inform_2.head, inform_2.line_num);
	}

}


/**
 * monty_mul - multiplie the two first element of a doubly linked list
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_mul(stack_t **head, unsigned int line_num)
{
	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_stack(&inform_2.head);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n = (*head)->next->n * (*head)->n;
		monty_pop(&inform_2.head, inform_2.line_num);
	}

}


/**
 * monty_mod - get the modulo the second element of the stack
 * by the top element of the stack
 * @head: points to head of the list
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 *
 */

void monty_mod(stack_t **head, unsigned int line_num)
{
	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_stack(&inform_2.head);
		free(inform_2.line);
		fclose(inform_2.file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_num);
			free_stack(&inform_2.head);
			free(inform_2.line);
			fclose(inform_2.file_ptr);
			exit(EXIT_FAILURE);

		}
		(*head)->next->n = (*head)->next->n % (*head)->n;
		monty_pop(&inform_2.head, inform_2.line_num);
	}

}
