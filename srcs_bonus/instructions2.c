/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:48:26 by pavicent          #+#    #+#             */
/*   Updated: 2024/10/17 13:48:29 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate_both_bn(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_bn(stack_a);
	reverse_rotate_bn(stack_b);
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_bn(stack_a);
	swap_bn(stack_b);
}
