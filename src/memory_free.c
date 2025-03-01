/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:52:48 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 08:25:05 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    free_params(char **buffer)
{
    int i;

    i = 0;
    while (buffer[i] != NULL)
    {
        free(buffer[i]);
        i++;
    }
    free(buffer);
}

void	memory_free(t_data *data)
{
    if (data)
    {
        if (data->buffer)
            free_params(data->buffer);
        free(data);
    }
}