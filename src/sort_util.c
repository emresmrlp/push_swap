/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:03:14 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 17:18:39 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_min(t_data *data, int value)
{
    int i;

    i = 0;
    while (i < data->size_a)
    {
        if (data->a[i] < value)
            return (0);
        i++;
    }
    return (1);
}

int is_max(t_data *data, int value)
{
    int i;

    i = 0;
    while (i < data->size_a)
    {
        if (data->a[i] > value)
            return (0);
        i++;
    }
    return (1);
}
