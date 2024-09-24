/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:10:02 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/24 15:14:28 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//prepares the cheapest node on top of a to push to b, leaving 3 nodes in a 
static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

//prepares b nodes to push them back to stack a
static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

//function that moves the smallest number to the top
static void	min_on_top(t_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

//function that sort stack a if it has more than 3 numbers
void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
