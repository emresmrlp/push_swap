/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:19:13 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 21:21:36 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include        <stdio.h>
void set_index(t_stack **stack)
{
    int i;
    int median;
    t_stack *temp;

    temp = *stack;
    median = get_size(stack) / 2;
    i = 0;
    while (temp)
    {
        temp->index = i;
        if (i < median)
            temp->above_median = 1;
        else
            temp->above_median = 0;
        temp = temp->next;
        i++;
    }
}

void    min_to_top(t_data *data)
{
    while (get_min(data->stack_a)->value != (*data->stack_a)->value)
    {
        if (get_min(data->stack_a)->above_median)
            rotate_a(data);
        else
            rev_rotate_a(data);
    }
}