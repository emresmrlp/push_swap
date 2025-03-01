/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:21:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 20:20:31 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three(t_data *data)
{
    if (stack_is_sorted(data))
        return ;
    if (is_min(data, data->a[0]))
	{
		rev_rotate_a(data);
		swap_a(data);
	}
	else if (is_max(data, data->a[0]))
	{
		rotate_a(data);
		if (!stack_is_sorted(data))
			swap_a(data);
	}
	else
	{
		if (is_min(data, data->a[1]))
			swap_a(data);
		else
			rev_rotate_a(data);
	}
}

void sort_four(t_data *data)
{
    if (stack_is_sorted(data))
        return ;
    if (is_min(data, data->a[0]))
        push_b(data);
    else if (is_min(data, data->a[1]))
    {
        swap_a(data);
        push_b(data);
    }
    else
    {
        while (!is_min(data, data->a[0]))
            rotate_a(data);
        push_b(data);
    }
    sort_three(data);
    push_a(data);
}

void sort_five(t_data *data)
{
    if (stack_is_sorted(data))
        return ;
    if (is_min(data, data->a[0]))
        push_b(data);
    else if (is_min(data, data->a[1]))
    {
        rotate_a(data);
        push_b(data);
    }
    else
    {
        while (!is_min(data, data->a[0]))
            rotate_a(data);
        push_b(data);
    }
    sort_four(data);
    push_a(data);
}

void quick_sort(t_data *data)
{
    int median;

    median = get_median_of_three(data);
}