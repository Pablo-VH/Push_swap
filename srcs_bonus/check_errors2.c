/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:21:40 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/30 11:21:42 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	content_bn(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j += str_isdigit_bn(argv[i]);
		i++;
	}
	return (j);
}

int	str_isdigit_bn(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	display_error3_bn(int *numbers, t_stack *stack_a, t_stack *stack_b)
{
	write(2, "KO\n", 3);
	free(numbers);
	free_stack_bn(stack_a);
	free_stack_bn(stack_b);
	exit(EXIT_FAILURE);
}
