/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:23:24 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 16:29:27 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rev_rotate_a(t_data *data)
{
	int	temp;

	if (data->size_a <= 1)
		return (1);
	temp = data->a[data->size_a - 1];
	shift_down_a(data);
	data->a[0] = temp;
	ft_printf("rra\n");
	return (0);
}

int	rev_rotate_b(t_data *data)
{
	int	temp;

	if (data->size_b <= 1)
		return (1);
	temp = data->b[data->size_b - 1];
	shift_down_b(data);
	data->b[0] = temp;
	ft_printf("rrb\n");
	return (0);
}

int	rev_rotate_ab(t_data *data)
{
	int	temp;

	if (data->size_a <= 1)
		return (1);
	else
	{
		temp = data->a[data->size_a - 1];
		shift_down_a(data);
		data->a[0] = temp;
	}
	if (data->size_b <= 1)
		return (1);
	else
	{
		temp = data->b[data->size_b - 1];
		shift_down_b(data);
		data->b[0] = temp;
	}
	ft_printf("rrr\n");
	return (0);
}
