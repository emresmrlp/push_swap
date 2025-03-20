/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:03:15 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/20 08:46:15 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void both_rotate_operations(t_data *data, t_stack *node)
{
    while (node->ra > 0 && node->rb > 0)
    {
        rotate_ab(data);
        node->ra--;
        node->rb--;
    }
    while (node->rra > 0 && node->rrb > 0)
    {
        rev_rotate_ab(data);
        node->rra--;
    }
}

void rotate_operations(t_data *data, t_stack *node)
{
    while (node->ra > 0)
    {
        rotate_a(data);
        node->ra--;
    }
    while (node->rb > 0)
    {
        rotate_b(data);
        node->rb--;
    }
    while (node->rra > 0)
    {
        rev_rotate_a(data);
        node->rra--;
    }
    while (node->rrb > 0)
    {
        rev_rotate_b(data);
        node->rrb--;
    }
}
