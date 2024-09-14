/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:07:13 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/14 01:46:55 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//initialize a stack

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	push_node(t_stack **stack, long value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
//		if (error_syntax(argv[i]))
//			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
//		if (error_duplicate(*a, (int)n))
//			free_errors(a);
		push_node(a, n);
		i++;
	}
}

//find the last node of the list

t_stack	*find_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

//print a stack

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("Value: %ld, index: %d\n", stack->value, stack->index);
        stack = stack->next;
    }
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

//handle errors
void	free_errors(t_stack **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

//check errors on function arguments (syntax and duplicates)


