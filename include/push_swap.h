/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:42:02 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 19:51:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../external/libft/libft.h"
# include "../external/ft_printf/ft_printf.h"

typedef struct s_data
{
	int		*a;
	int		*b;
	int		size;
	int		size_a;
	int		size_b;
	int 	median;
	char	**buffer;
}	t_data;

int		init(t_data *data);
void	sort(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);
void	quick_sort(t_data *data);
int		get_median_of_three(t_data *data);
int		is_min(t_data *data, int value);
int		is_max(t_data *data, int value);
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
void	shift_up_a(t_data *data);
void	shift_up_b(t_data *data);
void   	shift_down_a(t_data *data);
void	shift_down_b(t_data *data);
int		program_exit(t_data *data);
int		program_exit_with_error(t_data *data);
int		param_controls(t_data *data, int ac, char **av);
int		param_count(char **av);
int		stack_is_sorted(t_data *data);
int		stack_controls(t_data *data);
void	free_params(t_data *data);
void	memory_free(t_data *data);

#endif