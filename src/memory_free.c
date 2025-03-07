/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:52:48 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 15:55:54 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_params(t_data *data)
{
	int	i;

	i = 0;
	while (data->buffer[i] != NULL)
	{
		free(data->buffer[i]);
		i++;
	}
	free(data->buffer);
	data->buffer = NULL;
}

void	free_stack(t_data *data)
{
	t_stack	*tmp;

	if (data->stack_a)
	{
		while (*data->stack_a)
		{
			tmp = *data->stack_a;
			*data->stack_a = (*data->stack_a)->next;
			free(tmp);
		}
		free(data->stack_a);
		data->stack_a = NULL;
	}
	if (data->stack_b)
	{
		while (*data->stack_b)
		{
			tmp = *data->stack_b;
			*data->stack_b = (*data->stack_b)->next;
			free(tmp);
		}
		free(data->stack_b);
		data->stack_b = NULL;
	}
}

void	memory_free(t_data *data)
{
	if (data)
	{
		if (data->buffer)
			free_params(data);
		if (data->stack_a || data->stack_b)
			free_stack(data);
		free(data);
	}
}
