/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:07:13 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/15 19:34:35 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//find the last node of the list/stack
t_stack	*find_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}



//free a stack
void	free_stack(t_stack **top)
{
	t_stack	*temp;

	while (*top != NULL)
	{
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}

//print a stack
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Value: %ld\n", stack->value);
		stack = stack->next;
	}
}

//Pop an Element from the Stack
long	pop(t_stack **stack)
{
	t_stack	*temp;
	long	value;


	if (*stack == NULL)
		return (-1);
	temp = *stack;
	value = temp->value;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
	return (value);
}
