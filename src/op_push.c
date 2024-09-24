/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:34:04 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/24 12:17:31 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// push a node into the other stack (pa/pb)
static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!src || !dst || !*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (*dst == NULL)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

//push a node from stack b into stack a
void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

//push a node from stack a into stack b
void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
