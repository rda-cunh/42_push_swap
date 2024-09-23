/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:33:57 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/24 00:58:09 by rda-cunh         ###   ########.fr       */
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
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//stack initialization and argument parsing
void	init_stack(t_stack **a, char **argv, int argc);
char	**split(char *str, char sep);

//nodes initialization
void	init_nodes_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	current_index(t_stack *stack);
void	init_nodes_b(t_stack *a, t_stack *b);

//error handling
void	free_errors(t_stack **a, char **argv, int argc);
void	free_stack(t_stack **stack);
void	free_argv_split(char **argv);
int		error_duplicate(t_stack *a, int n);
int		error_syntax(char *str);

//stack utils functions
t_stack	*find_last(t_stack *stack);
void	print_stack(t_stack *stack, char *name);
long	pop(t_stack **top);
bool	stack_sorted(t_stack *stack);

//stack operations functions
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack*cheapest_node);

//sort functions
void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);

//sort utils functions
int		stack_len(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);

#endif