/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:06:56 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 11:20:17 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
}

static int init_stacks(t_data *data)
{
	int i;

	data->a = (int *)ft_calloc(data->size_a, sizeof(int));
	if (!data->a)
		return (1);
	data->b = (int *)ft_calloc(data->size_a, sizeof(int));
	if (!data->b)
		return (1);
	i = 0;
	while (data->buffer[i] != NULL)
	{
		data->a[i] = ft_atoi(data->buffer[i]);
		i++;
	}
	free_params(data);
	return (0);
}

int	init(t_data *data)
{
	data->size_a = param_count(data);
	data->size_b = 0;
	init_data(data);
	if (init_stacks(data))
		return (1);
	return (0);
}
