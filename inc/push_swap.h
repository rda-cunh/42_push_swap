/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:33:57 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/15 19:28:50 by rda-cunh         ###   ########.fr       */
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

//stack initialization and argument parsing
void	init_stack(t_stack **a, char **argv);
char	**split(char *s, char c);

//error handling
void	free_errors(t_stack **a);

//utils functions
t_stack	*find_last(t_stack *stack);
void	print_stack(t_stack *stack);
void	free_stack(t_stack **top);
long	pop(t_stack **top);



//parsing argument (if needed)


//stack operations functions
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

#endif