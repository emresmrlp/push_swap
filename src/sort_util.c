/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:03:14 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 19:47:56 by ysumeral         ###   ########.fr       */
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

int get_median_of_three(t_data *data)
{
    if (data->size_a < 3)
    {
        if (data->size_a == 1)
            return (data->a[0]);
        else
        {
            if (data->a[0] > data->a[1])
                return (data->a[0]);
            else
                return (data->a[1]);
        }
    }
    if (data->a[0] > data->a[data->size / 2] &&
         data->a[0] < data->a[data->size - 1])
        return (data->a[0]);
    else if (data->a[data->size / 2] > data->a[0] &&
         data->a[data->size / 2] < data->a[data->size - 1])
        return (data->a[data->size / 2]);
    else
        return (data->a[data->size - 1]);
}
