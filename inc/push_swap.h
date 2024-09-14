/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:33:57 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/14 01:45:10 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //to remove later
# include <stdlib.h> 
# include <stdbool.h>
# include <limits.h> 
# include "../libft/libft.h"

//linked list node structure
typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//utils functions

void	init_stack(t_stack **a, char **argv);

void	print_stack(t_stack *stack);
void	free_stack(t_stack **top);
t_stack	*find_last(t_stack *stack);
void	free_errors(t_stack **a);

char	**split(char *s, char c);

//stack operations functions
void	push(t_stack **top, long value, int index);
long	pop(t_stack **top);
void	swap(t_stack **top);
void	rotate(t_stack **top);
void	reverse_rotate(t_stack **top);

#endif