/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:42:02 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/20 08:14:20 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../external/libft/libft.h"
# include "../external/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int ra;
	int rb;
	int rra;
	int rrb;
	int value;
	int index;
	int above_median;
	int cost;
	int cheapest;
	struct s_stack *target;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

typedef struct s_data
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**buffer;
	int		size;
}	t_data;

t_stack	*create_node(int value);
t_stack	*get_min(t_stack *stack);
t_stack	*get_max(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);
void	set_targets_a(t_stack *stack_a, t_stack *stack_b);
void	set_targets_b(t_stack *stack_a, t_stack *stack_b);
void	calc_cost_a(t_stack *stack_a, t_stack *stack_b);
void	calc_cost_b(t_stack *stack_a, t_stack *stack_b);
void 	both_rotate_operations(t_data *data, t_stack *node);
void	rotate_operations(t_data *data, t_stack *node);
void    min_to_top(t_data *data);
void	set_index(t_stack **stack);
void	add_node(t_stack **stack, t_stack *node);
int		program_init(t_data *data);
void	sort_handler(t_data *data);
void	sort_three(t_data *data);
void	sort_algorithm(t_data *data);
int		get_size(t_stack **stack);
int		push_a(t_data *data);
int		push_b(t_data *data);
int		swap_a(t_data *data);
int		swap_b(t_data *data);
int		swap_ab(t_data *data);
int		rotate_a(t_data *data);
int		rotate_b(t_data *data);
int		rotate_ab(t_data *data);
int		rev_rotate_a(t_data *data);
int		rev_rotate_b(t_data *data);
int		rev_rotate_ab(t_data *data);
int		program_exit(t_data *data);
int		program_exit_with_error(t_data *data);
int		param_controls(t_data *data, int ac, char **av);
int		param_count(char **av);
int		is_sorted(t_stack **stack);
int		stack_controls(t_data *data);
void	free_params(t_data *data);
void	memory_free(t_data *data);

#endif