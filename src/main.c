/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:59:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/11 17:00:27 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*sa;
	t_stack	*sb;

	sa = NULL;
	sb = NULL;
	if (argc < 2)
		return (0);
	//missing introduce a function to check arguments for errors

	//missing function to handle both cases "command line arguments or a splited string"

	//add numbers to our stack a
    int i = argc - 1;
	while(i > 0)
	{
    	int value = atoi(argv[i]);
        push(&sa, value, argc - i - 1);
        i--; 
    }

    ft_printf("Initial stack a:\n");
    print_stack(sa);

	//missing checking if the 

    free_stack(&sa);
	free_stack(&sb);
    return (0);
}

