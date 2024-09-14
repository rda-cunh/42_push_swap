/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:34:04 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/14 02:31:42 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// push a and push b (pa/pb)

static void	*push(t_stack **dst, t_stack **src)
{
	t_stack *push_node;

	if (!*src)
		return ; 
	push_node = *src;
	*src = (*src)->next;
}



//Pop an Element from the Stack

long	pop(t_stack **top)
{
	if (*top == NULL)
		return (-1); 
	t_stack *temp = *top;
	long value = temp->value;
	*top = (*top)->next;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(temp);
	return (value);
}

//Swap the Top Two Elements

void	swap(t_stack **top)
{
	if (*top == NULL || (*top)->next == NULL)
		return ;
	t_stack *first = *top;
	t_stack *second = first->next;
	
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL; 
	second->next = first; 
	first->prev = second;

	*top = second; 
}

//Rotate the Stack

void	rotate(t_stack **top)
{
	if (*top == NULL || (*top)->next == NULL)
		return ;
	
	t_stack	*first = *top;
	t_stack	*last = *top;

	while (last->next != NULL)
		last = last->next;

	*top = first->next; 
	(*top)->prev = NULL;
	
	first->next = NULL;
	last->next = first;
	first->prev = last;

}

//Reverse Rotate the Stack

void	reverse_rotate(t_stack **top)
{
	if (*top == NULL || (*top)->next == NULL)
		return ; 

	t_stack *last = *top;
	while(last->next != NULL)
		last = last->next;

	if (last->prev != NULL)
		last->prev->next = NULL;

	last->prev = NULL;
	last->next = *top;  
	(*top)->prev = last;
	*top = last; 
}


