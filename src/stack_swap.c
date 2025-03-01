/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:44:58 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 16:27:28 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_a(t_data *data)
{
	int	temp;

	if (data->size_a <= 1)
		return (1);
	temp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = temp;
	ft_printf("sa\n");
	return (0);
}

int	swap_b(t_data *data)
{
	int	temp;

	if (data->size_b <= 1)
		return (1);
	temp = data->b[0];
	data->b[0] = data->b[1];
	data->b[1] = temp;
	ft_printf("sb\n");
	return (0);
}

int	swap_ab(t_data *data)
{
	int	temp;

	if (data->size_a <= 1)
		return (1);
	else
	{
		temp = data->a[0];
		data->a[0] = data->a[1];
		data->a[1] = temp;
	}
	if (data->size_b <= 1)
		return (1);
	else
	{
		temp = data->b[0];
		data->b[0] = data->b[1];
		data->b[1] = temp;
	}
	ft_printf("ss\n");
	return (0);
}
