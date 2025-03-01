/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:13:11 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 16:29:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate_a(t_data *data)
{
	int	temp;

	if (data->size_a <= 1)
		return (1);
	temp = data->a[0];
	shift_up_a(data);
	data->a[data->size_a - 1] = temp;
	ft_printf("ra\n");
	return (0);
}

int	rotate_b(t_data *data)
{
	int	temp;

	if (data->size_b <= 1)
		return (1);
	temp = data->b[0];
	shift_up_b(data);
	data->b[data->size_b - 1] = temp;
	ft_printf("rb\n");
	return (0);
}

int	rotate_ab(t_data *data)
{
	int	temp;

	if (data->size_a <= 1)
		return (1);
	else
	{
		temp = data->a[0];
		shift_up_a(data);
		data->a[data->size_a - 1] = temp;
	}
	if (data->size_b <= 1)
		return (1);
	else
	{
		temp = data->b[0];
		shift_up_b(data);
		data->b[data->size_b - 1] = temp;
	}
	ft_printf("rr\n");
	return (0);
}
