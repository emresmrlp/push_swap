/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:06:56 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 16:43:08 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	init_stacks(t_data *data)
{
	int	i;

	data->stack_a = (t_stack **)ft_calloc(data->size, sizeof(t_stack *));
	if (!data->stack_a)
		return (1);
	data->stack_b = (t_stack **)ft_calloc(data->size, sizeof(t_stack *));
	if (!data->stack_b)
		return (1);
	i = 0;
	while (data->buffer[i] != NULL)
	{
		add_node(data->stack_a, create_node(ft_atol(data->buffer[i])));
		i++;
	}
	return (0);
}

int	program_init(t_data *data)
{
	if (init_stacks(data))
		return (1);
	return (0);
}
