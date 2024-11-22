/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:02:37 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/29 13:02:39 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				data;
	int				s_index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}			t_stack;

int		*arg_parse_bn(int argc, char **argv, int count);
int		check_digits_bn(int argc, char **argv);
int		check_dup_bn(int *numbers, int count);
int		content_bn(char **argv);
int		ft_check_len_bn(char *numbers);
int		ft_index_bn(int n, int *arr);
int		instructions(t_stack *stack_a, t_stack *stack_b, char *line);
int		instructions_2(t_stack *stack_a, t_stack *stack_b, char *line);
int		is_sorted_bn(t_stack *stack);
int		str_isdigit_bn(char *argv);
int		take_top_bn(t_stack *stack);
int		open_inst(t_stack *stack_a, t_stack *stack_b);
void	check_range_bn(char **s_numbers, int *numbers);
void	init_stack_bn(t_stack *stack_a, t_stack *stack_b, int *nb, int count);
void	display_error_bn(int c, int *numbers);
void	display_error2_bn(int *numbers, t_stack *stack_a, t_stack *stack_b);
void	free_2d_bn(char **str);
void	free_stack_bn(t_stack *stack);
void	init_inst(t_stack *stack_a, t_stack *stack_b, int *numbers);
void	insertion_sort_bn(int array[], int n);
void	push_bn(t_stack *stack1, t_stack *stack2);
void	push_stack_bn(t_stack *stack, int index, int data);
void	reverse_rotate_bn(t_stack *stack);
void	reverse_rotate_both_bn(t_stack *stack_a, t_stack *stack_b);
void	rotate_bn(t_stack *stack);
void	rotate_both_bn(t_stack *stack_a, t_stack *stack_b);
void	swap_bn(t_stack *stack);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

#endif
