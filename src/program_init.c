/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:06:56 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 09:34:51 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->buffer = NULL;
}

int	init(t_data *data)
{
	init_data(data);
	return (0);
}
