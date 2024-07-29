/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:33:57 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/07/29 17:48:02 by rda-cunh         ###   ########.fr       */
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

t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
int	pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	free_stack(t_stack *stack);

#endif