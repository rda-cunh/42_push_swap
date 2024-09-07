/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:33:57 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/07 23:08:12 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack 
{
    long value;
    int index; 
    struct s_stack *next;
    struct s_stack *prev; 
} t_stack; 

void	push(t_stack **top, long value, int index);
long	pop(t_stack **top);
void	swap(t_stack **top);
void	rotate(t_stack **top);
void	reverse_rotate(t_stack **top);
void	free_stack(t_stack **top);

#endif