/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:57:50 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/15 11:57:53 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(int c, int *numbers)
{
	write(2, "Error\n", 6);
	if (c > 1)
		free(numbers);
	exit(EXIT_FAILURE);
}

void	display_error2(int *numbers, t_stack *stack_a)
{
	write(2, "Error\n", 6);
	free(numbers);
	free(stack_a);
	exit(EXIT_FAILURE);
}
