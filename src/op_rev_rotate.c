/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:55:11 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/24 12:57:37 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//reverse rotate a stack node
void	rev_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

//reverse rotate stack a
void	rra(t_stack **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

//reverse rotate stack b
void	rrb(t_stack **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

//reverse rotate stacks a and b
void	rrr(t_stack **a, t_stack **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}

//rotates to bring the desired nodes (cheapest_node and target_node) to the top
//used in sorting algo to reduce the number of movements
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack*cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
