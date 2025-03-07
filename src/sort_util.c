/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:03:14 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 20:59:54 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *get_min(t_stack **stack)
{
    t_stack *min;
    t_stack *temp;

    temp = *stack;
    min = temp;
    while (temp)
    {
        if (temp->value < min->value)
            min = temp;
        temp = temp->next;
    }
    return (min);
}

t_stack *get_max(t_stack **stack)
{
    t_stack *max;
    t_stack *temp;

    temp = *stack;
    max = temp;
    while (temp)
    {
        if (temp->value > max->value)
            max = temp;
        temp = temp->next;
    }
    return (max);
}