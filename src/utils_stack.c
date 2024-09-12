/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:07:13 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/12 22:48:59 by rda-cunh         ###   ########.fr       */
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

void	push_node(t_stack **stack, long value)
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
 

}


void	init_stack(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		push_node(a, n);
		i++;
	}
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
