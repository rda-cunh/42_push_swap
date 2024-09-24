/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:07:55 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/24 12:55:43 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//rotate a number to the end of a stack
static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

//rotate the first number of stack a into the end of the stack
void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

//rotate the first number of stack b into the end of the stack
void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

//rotate the first numbers of stack a and b
void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

//rotates to bring the desired nodes (cheapest_node and target_node) to the top
//used in sorting algo to reduce the number of movements
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
