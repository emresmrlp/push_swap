/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:21:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 20:43:53 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three(t_data *data)
{
	int max;

	max = get_max(data->stack_a)->value;
    if (is_sorted(data->stack_a))
        return ;
    if ((*data->stack_a)->value == max)
		rotate_a(data);
	else if ((*data->stack_a)->next->value == max)
		rev_rotate_a(data);
	if ((*data->stack_a)->value > (*data->stack_a)->next->value)
		swap_a(data);
}
