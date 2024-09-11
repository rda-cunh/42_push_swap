/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:59:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/11 15:28:45 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    t_stack *sa = NULL;
	t_stack *sb = NULL;
    int i = 1;
    while(i < argc)
    {
        int value = atoi(argv[i]);
        push(&sa, value, i - 1);
        i++; 
    }

    printf("Initial stack a:\n");
    print_stack(sa);

    swap(&sa);
    printf("After swap:\n");
    print_stack(sa);

    rotate(&sa);
    printf("After rotate:\n");
    print_stack(sa);

    reverse_rotate(&sa);
    printf("After reverse rotate:\n");
    print_stack(sa);

    pop(&sa);
    printf("After pop:\n");
    print_stack(sa);

    free_stack(&sa);
	free_stack(&sb);
    return (0);
}

