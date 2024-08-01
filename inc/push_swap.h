/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:54:05 by pavicent          #+#    #+#             */
/*   Updated: 2024/07/05 11:54:08 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

// Colours
# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;97m"
# define RESET "\033[0m"

typedef int			t_bool;
# define TRUE 1
# define FALSE 0

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

///////////////////// SORTING /////////////////////

int		count_r(t_node *stack, int index);
int		ft_index(int n, int *arr);
int		ft_sqrt(int number);
int		get_min_index(t_stack *stack);
int		is_rot_sort(t_stack *stack, int min_s_index);
int		is_sorted(t_stack *stack);
void	insertion_sort(int array[], int n);
void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length);
void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length);
void	simple_sort(t_stack *stack, int length);
void	sort(t_stack *stack_a, t_stack *stack_b, int *numbers, int length);

/////////////////// STRUCT UTILS ///////////////////

int		take_top(t_stack *stack);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int *numbers, int count);
void	push_stack(t_stack *stack, int index, int data);

///////////////////// PARSING //////////////////////

int		*arg_parse(int argc, char **argv, int count);
int		check_digits(int argc, char **argv);
int		check_dup_bf(int *numbers, int count);
void	check_range(char **s_numbers, int *numbers);
int		content(char **argv);
void	display_error(int c, int *numbers);
void	display_error2(int *numbers, t_stack *stack_a);
void	free_2d(char **str);
void	free_stack(t_stack *stack);
int		ft_check_len(char *numbers);
int		str_isdigit(char *argv);

////////////////// INSTRUCTIONS ////////////////////

void	rotate(t_stack *stack, char x, t_bool b);
void	reverse_rotate(t_stack *stack, char x, t_bool b);
void	swap(t_stack *stack, char x, t_bool b);
void	push(t_stack *stack1, t_stack *stack2, char x, t_bool b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);

#endif
