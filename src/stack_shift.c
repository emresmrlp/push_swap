/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:38:18 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 16:26:55 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	shift_up_a(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
}

void	shift_up_b(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_b - 1)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
}

void	shift_down_a(t_data *data)
{
	int	i;

	if (data->size_a == 0)
		return ;
	if (data->size_b == data->size)
		i = data->size_a - 2;
	else
		i = data->size_a - 1;
	while (i >= 0)
	{
		data->a[i + 1] = data->a[i];
		i--;
	}
}

void	shift_down_b(t_data *data)
{
	int	i;

	if (data->size_b == 0)
		return ;
	if (data->size_a == data->size)
		i = data->size_b - 2;
	else
		i = data->size_b - 1;
	while (i >= 0)
	{
		data->b[i + 1] = data->b[i];
		i--;
	}
}
