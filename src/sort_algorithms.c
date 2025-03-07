/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:21:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 18:02:47 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three(t_data *data)
{
	t_stack *stack_a;

	stack_a = *data->stack_a;
    if (is_sorted(data->stack_a))
        return ;
    if (get_min(data->stack_a) == stack_a->value)
	{
		rev_rotate_a(data);
		swap_a(data);
	}
	else if (get_max(data->stack_a) == stack_a->value)
	{
		rotate_a(data);
		if (!is_sorted(data->stack_a))
			swap_a(data);
    }
	else
	{
		if (get_min(data->stack_a) == stack_a->next->value)
			swap_a(data);
		else
			rev_rotate_a(data);
	}
}
