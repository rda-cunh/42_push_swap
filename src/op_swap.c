/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:07:24 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/24 12:19:05 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//swap two first top numbers of a stack
static void	swap(t_stack **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

//swap two first top numbers of stack a
void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

//swap two first top numbers of stack b
void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

//swap two first top numbers of stack a and b
void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
