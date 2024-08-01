/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:02:18 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/29 13:02:20 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	insertion_sort_bn(int array[], int n)
{
	int	element;
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		element = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > element)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = element;
		i++;
	}
}

int	ft_index_bn(int n, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != n)
		i++;
	return (i);
}

void	push_stack_bn(t_stack *stack, int index, int data)
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

void	init_stack_bn(t_stack *stack_a, t_stack *stack_b, int *nb, int count)
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
		push_stack_bn(stack_a, 0, nb[i]);
		i--;
	}
	insertion_sort_bn(nb, count);
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->s_index = ft_index_bn(tmp->data, nb);
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
	count = check_digits_bn(argc, argv);
	if (count < 1 || content_bn(argv) != 0)
		display_error_bn(1, numbers);
	numbers = arg_parse_bn(argc, argv, count);
	if (!numbers)
		exit(EXIT_FAILURE);
	if (check_dup_bn(numbers, count))
		display_error_bn(2, numbers);
	init_stack_bn(&stack_a, &stack_b, numbers, count);
	open_inst(&stack_a, &stack_b);
	if (!is_sorted_bn(&stack_a))
		display_error2_bn(numbers, &stack_a);
	ft_printf("Ok\n");
	free(numbers);
	free_stack_bn(&stack_a);
	return (EXIT_SUCCESS);
}
