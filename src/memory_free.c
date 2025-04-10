/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:52:48 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:22 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_params(t_data *data)
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

static void	free_stacks(t_data *data)
{
	t_stack	*current;
	t_stack	*next;

	if (data->stack_a)
	{
		current = data->stack_a;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		data->stack_a = NULL;
	}
	if (data->stack_b)
	{
		current = data->stack_b;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
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
			free_stacks(data);
		free(data);
	}
}
