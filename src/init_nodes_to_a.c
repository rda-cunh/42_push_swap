/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:10:26 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/23 00:35:44 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	current_index(t_stack *stack)
{
	int i;
	int	median;

	i = 0; 
	if (!stack)
		return ; 
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i; 
		if (i <= median)
			stack->above_median = true; 
		else
			stack->above_median = false; 
		stack = stack->next; 
		++i; 
	}
}

static void	set_target_a(t_stack *a; t_stack = *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next; 
		}
	}
}


void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
