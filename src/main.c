/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:59:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/07 23:10:26 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/push_swap.h"

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("Value: %ld, index: %d\n", stack->value, stack->index);
        stack = stack->next;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Incorrect number of arguments provided\n");
        return (1);
    }

    t_stack *stack = NULL;
    int i = 1;
    while(i < argc)
    {
        int value = atoi(argv[i]);
        push(&stack, value, i - 1);
        i++; 
    }

    printf("Initial stack:\n");
    print_stack(stack);

    swap(&stack);
    printf("After swap:\n");
    print_stack(stack);

    rotate(&stack);
    printf("After rotate:\n");
    print_stack(stack);

    reverse_rotate(&stack);
    printf("After reverse rotate:\n");
    print_stack(stack);

    pop(&stack);
    printf("After pop:\n");
    print_stack(stack);

    free_stack(&stack);
    return (0);
}

