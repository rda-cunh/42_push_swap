/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:07:13 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/10 00:08:09 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Value: %ld, index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
}
