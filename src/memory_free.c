/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:52:48 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 09:34:34 by ysumeral         ###   ########.fr       */
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

void	memory_free(t_data *data)
{
	if (data)
	{
		if (data->buffer)
			free_params(data);
		free(data);
	}
}
