/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:59:48 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/07/17 13:05:24 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void    print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while(current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Incorrect number of arguments provided\n");
        return (1);
    }

    t_stack *stack = init_stack();
    if (!stack)
    {
        printf("Error initializing stack\n");
        return (1);
    }

    int i = argc - 1;
    while(i > 0)
    {
        int value = atoi(argv[i]);
        push(stack, value);
        i--; 
    }

    printf("Initial stack: ");
    print_stack(stack); 

    swap(stack);
    printf("After swap: ");
    print_stack(stack); 

    rotate(stack);
    printf("After rotate: ");
    print_stack(stack); 

    reverse_rotate(stack);
    printf("After reverse rotate: ");
    print_stack(stack); 

    int popped_value = pop(stack);
    printf("Popped value: %d\n", popped_value);
    printf("After pop: ");
    print_stack(stack);

    free_stack(stack);
    return (0);
}