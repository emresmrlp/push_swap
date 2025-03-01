/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:11:09 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 11:33:07 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int stack_check_max_min(t_data *data)
{
    int i;

    i = 0;
    while (i < data->size_a)
    {
        if (data->a[i] > INT_MAX || data->a[i] < INT_MIN)
            return (1);
        i++;
    }
    return (0);
}

static int stack_check_sorted(t_data *data)
{
    int i;

    i = 0;
    while (i < data->size_a)
    {
        if (data->a[i + 1] == '\0')
            break ;
        if (data->a[i] > data->a[i + 1])
            return (1);
        i++;
    }
    return (0);
}

int	stack_controls(t_data *data)
{
    if (stack_check_max_min(data))
        return (1);
    if (!stack_check_sorted(data))
        return (-1);
    return (0);
}