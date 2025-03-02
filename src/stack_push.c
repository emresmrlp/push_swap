/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:44:58 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/02 11:30:29 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_a(t_data *data)
{
	if (data->size_b == 0)
		return (1);
	shift_down_a(data);
	data->a[0] = data->b[0];
	shift_up_b(data);
	data->size_a++;
	data->size_b--;
	ft_printf("pa\n");
	return (0);
}

int	push_b(t_data *data)
{
	if (data->size_a == 0)
		return (1);
	shift_down_b(data);
	data->b[0] = data->a[0];
	shift_up_a(data);
	data->size_a--;
	data->size_b++;
	ft_printf("pb\n");
	return (0);
}

int	push_a_all(t_data *data)
{
	while (data->size_b > 0)
		push_a(data);
	return (0);
}
