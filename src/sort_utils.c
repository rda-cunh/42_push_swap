/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:54:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/14 02:25:22 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//check if the stack is sorted
bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//check the lenght of the stack
int	stack_len(t_stack *stack)
{
	int	count;

	if (stack != NULL)
		return (NULL);
	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

//search a stack and finds the node with the biggest number
t_stack	*find_max(t_stack *stack)
{
	long	max; 
	t_stack	*max_node; 

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

//search a stack and finds the node with the smallest number
t_stack *find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node; 

	if (!stack)
		return (NULL);
	min = LONG_MAX; 
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack; 
		}
		stack = stack->next; 
	}
	return (min_node); 
}