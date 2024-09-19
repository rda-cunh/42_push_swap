//missing header

#include "../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a); 
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false); 
}
