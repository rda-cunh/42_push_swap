/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:34:04 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/07/29 16:53:09 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/push_swap.h"

// Initialize a Stack

t_stack	*init_stack(void)
{
	t_stack	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

//Push an Element onto the Stack (carefull!: not from stack b)

void	push(t_stack *stack, int value)
{
	t_node	*new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

//Pop an Element from the Stack

int	pop(t_stack *stack)
{
	if (stack->top == NULL)
		return (-1); 
	t_node *temp = stack->top;
	int value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (value);
}

//Swap the Top Two Elements

void	swap(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	t_node *first = stack->top;
	t_node *second = stack->top->next;
	first->next = second->next;
	second->next = first; 
	stack->top = second;
}

//Rotate the Stack

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	t_node	*first = stack->top;
	t_node	*last = stack->top; 
	while (last->next != NULL)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

//Reverse Rotate the Stack

void	reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ; 
	t_node *prev = NULL;
	t_node *current = stack->top;
	while(current->next != NULL)
	{
		prev = current;
		current = current ->next;
	}
	current->next = stack->top; 
	stack->top = current;
	prev->next = NULL; 
}

//Free the Stack

void	free_stack(t_stack *stack)
{
	while (stack->top != NULL)
	{
		t_node *temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
}