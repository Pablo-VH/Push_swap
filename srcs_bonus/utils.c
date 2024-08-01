/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:39:17 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/29 13:39:19 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_2d_bn(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_stack_bn(t_stack *stack)
{
	while (stack)
		take_top_bn(stack);
}

void	display_error_bn(int c, int *numbers)
{
	write(2, "Error\n", 6);
	if (c > 1)
		free(numbers);
	exit(EXIT_FAILURE);
}

void	display_error2_bn(int *numbers, t_stack *stack_a)
{
	write(2, "Error\n", 6);
	free(numbers);
	free(stack_a);
	exit(EXIT_FAILURE);
}

void	open_inst(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		instructions(stack_a, stack_b, line);
		free(line);
	}
}
