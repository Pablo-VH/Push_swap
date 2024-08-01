/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:06:22 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/30 11:06:24 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	take_top_bn(t_stack *stack)
{
	t_node	*top;
	int		data;

	if (!stack->head)
		exit(EXIT_FAILURE);
	top = stack->head;
	data = top->data;
	stack->head = top->next;
	free(top);
	top = NULL;
	stack->size--;
	return (data);
}

int	is_sorted_bn(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if ((tmp->data) > (tmp->next->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	instructions(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strncmp(line, "pa", 5) == 0 || ft_strncmp(line, "pa\n", 5) == 0)
		push_bn(stack_a, stack_b);
	if (ft_strncmp(line, "pb", 5) == 0 || ft_strncmp(line, "pb\n", 5) == 0)
		push_bn(stack_b, stack_a);
	if (ft_strncmp(line, "ra", 5) == 0 || ft_strncmp(line, "ra\n", 5) == 0)
		rotate_bn(stack_a);
	if (ft_strncmp(line, "rb", 5) == 0 || ft_strncmp(line, "rb\n", 5) == 0)
		rotate_bn(stack_b);
	if (ft_strncmp(line, "rra", 5) == 0 || ft_strncmp(line, "rra\n", 5) == 0)
		reverse_rotate_bn(stack_a);
	if (ft_strncmp(line, "rrb", 5) == 0 || ft_strncmp(line, "rrb\n", 5) == 0)
		reverse_rotate_bn(stack_b);
	if (ft_strncmp(line, "sa", 5) == 0 || ft_strncmp(line, "sa\n", 5) == 0)
		swap_bn(stack_a);
	if (ft_strncmp(line, "sb", 5) == 0 || ft_strncmp(line, "sb\n", 5) == 0)
		swap_bn(stack_b);
	if (ft_strncmp(line, "rr", 5) == 0 || ft_strncmp(line, "rr\n", 5) == 0)
		rotate_both_bn(stack_a, stack_b);
}
