/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:59:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/12 21:59:00 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		argv = ft_spit(argv[1], ' ');
	init_stack(&a, argv + 1);

//to remove after testing
    ft_printf("Initial stack a:\n");
    print_stack(a);

	if (stack_sorted(a) == false)
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_turk(&a, &b);
	}

//to remove after testing
    ft_printf("Final stack a:\n");
    print_stack(a);
*/
	free_stack(&a);
	free_stack(&b);
	return (0);
}

