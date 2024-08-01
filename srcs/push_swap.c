/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:53:54 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/05 11:53:57 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack, int index, int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->s_index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *numbers, int count)
{
	int		i;
	t_node	*tmp;

	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	i = count - 1;
	while (i >= 0)
	{
		push_stack(stack_a, 0, numbers[i]);
		i--;
	}
	insertion_sort(numbers, count);
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->s_index = ft_index(tmp->data, numbers);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*numbers;

	numbers = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	count = check_digits(argc, argv);
	if (content(argv) > 0)
		display_error(1, numbers);
	if (count < 1)
		display_error(1, numbers);
	numbers = arg_parse(argc, argv, count);
	if (!numbers)
		exit(EXIT_FAILURE);
	if (check_dup_bf(numbers, count))
		display_error(2, numbers);
	init_stack(&stack_a, &stack_b, numbers, count);
	sort(&stack_a, &stack_b, numbers, count);
	free(numbers);
	free_stack(&stack_a);
	return (EXIT_SUCCESS);
}
