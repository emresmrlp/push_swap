/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:40:53 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:13 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_data *data)
{
	int	max;

	max = get_max(data->stack_a)->value;
	if (is_sorted(data->stack_a))
		return ;
	if (data->stack_a->value == max)
		rotate_a(data, 1);
	else if (data->stack_a->next->value == max)
		rev_rotate_a(data, 1);
	if (data->stack_a->value > data->stack_a->next->value)
		swap_a(data, 1);
}

void	sort_handler(t_data *data)
{
	if (data->size == 2)
		swap_a(data, 1);
	else if (data->size == 3)
		sort_three(data);
	else
		turk_sort(data);
}
