/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:52:48 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 12:34:56 by ysumeral         ###   ########.fr       */
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
	if (data->a)
		free(data->a);
	if (data->b)
		free(data->b);
}

void	memory_free(t_data *data)
{
	if (data)
	{
		if (data->buffer)
			free_params(data);
		free_stack(data);
		free(data);
	}
}
