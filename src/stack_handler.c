/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:11:09 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 19:39:35 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_is_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a)
	{
		if (data->a[i + 1] == '\0')
			break ;
		if (data->a[i] > data->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int stack_check_duplicate(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			if (data->a[i] == data->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	stack_controls(t_data *data)
{
	if (stack_check_duplicate(data))
		return (1);
	return (0);
}
