#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct data - global variable for function
 *
 * @head: pointer to the stacks
 * @line:pointer to line got from bytecode file
 * @line_num: line number in the file
 * @file_ptr: pointer to bytecode
 * @cmdline: 2d array to stor cmmand and values of opcode
*/

typedef struct data
{
	FILE *file_ptr;
	char cmdline[10][20];
	unsigned int line_num;
	stack_t *head;
	char *line;
} data;
extern data inform_2;



void monty_push(stack_t **head, unsigned int line_num);
void monty_pall(stack_t **head, unsigned int line_num);
void monty_pint(stack_t **head, unsigned int line_num);
void monty_pop(stack_t **head, unsigned int line_num);
void monty_swap(stack_t **head, unsigned int line_num);
void monty_add(stack_t **head, unsigned int line_num);
void monty_nop(stack_t **head, unsigned int line_num);
void monty_sub(stack_t **head, unsigned int line_num);
void monty_div(stack_t **head, unsigned int line_num);
void monty_mul(stack_t **head, unsigned int line_num);
void monty_mod(stack_t **head, unsigned int line_num);
void monty_pchar(stack_t **head, unsigned int line_num);
void monty_pstr(stack_t **head, unsigned int line_num);
void monty_rotl(stack_t **head, unsigned int line_num);

void free_stack(stack_t **head);


#endif /* MONTY_H */
