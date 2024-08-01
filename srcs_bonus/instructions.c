/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:06:35 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/30 11:06:37 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_bn(t_stack *stack1, t_stack *stack2)
{
	int	index;

	if (stack2->head == NULL)
		return ;
	index = stack2->head->s_index;
	push_stack_bn(stack1, index, take_top_bn(stack2));
}

void	rotate_bn(t_stack *stack)
{
	t_node	*tmp;
	t_node	*current;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	current = stack->head;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate_bn(t_stack *stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack->head || !stack->head->next || !stack)
		return ;
	current = stack->head;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = stack->head;
	stack->head = tmp;
}

void	swap_bn(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
}

void	rotate_both_bn(t_stack *stack_a, t_stack *stack_b)
{
	rotate_bn(stack_a);
	rotate_bn(stack_b);
}
