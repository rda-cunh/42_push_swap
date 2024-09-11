/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:07:13 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/11 15:31:52 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//print a stack

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("Value: %ld, index: %d\n", stack->value, stack->index);
        stack = stack->next;
    }
}

//free a Stack

void	free_stack(t_stack **top)
{
	while (*top != NULL)
	{
		t_stack *temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}
