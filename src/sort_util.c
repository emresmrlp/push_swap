/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:03:14 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/16 09:21:31 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
        if (i < median || temp->index == 0)
            temp->above_median = 1;
        else
            temp->above_median = 0;
        temp = temp->next;
        i++;
    }
}

void    min_to_top(t_data *data)
{
    while (get_min(*data->stack_a)->value != (*data->stack_a)->value)
    {
        if (get_min(*data->stack_a)->above_median)
            rotate_a(data);
        else
            rev_rotate_a(data);
    }
}

t_stack *get_min(t_stack *stack)
{
    t_stack *min;

    min = stack;
    while (stack)
    {
        if (stack->value < min->value)
            min = stack;
        stack = stack->next;
    }
    return (min);
}

t_stack *get_max(t_stack *stack)
{
    t_stack *max;

    max = stack;
    while (stack)
    {
        if (stack->value > max->value)
            max = stack;
        stack = stack->next;
    }
    return (max);
}