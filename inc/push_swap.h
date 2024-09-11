/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:33:57 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/11 15:35:56 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

// define linked list node structure
typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//utils functions
void	print_stack(t_stack *stack);
void	free_stack(t_stack **top);

//stack operations functions
void	push(t_stack **top, long value, int index);
long	pop(t_stack **top);
void	swap(t_stack **top);
void	rotate(t_stack **top);
void	reverse_rotate(t_stack **top);

#endif