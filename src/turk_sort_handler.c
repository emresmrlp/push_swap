/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:10:22 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:32:51 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	send_a_to_b(t_data *data)
{
	t_stack	*cheap;
	t_stack	*current;

	cheap = data->stack_a;
	set_index(data->stack_a);
	set_index(data->stack_b);
	set_targets_a(data->stack_a, data->stack_b);
	calc_cost_a(data->stack_a, data->stack_b);
	current = data->stack_a;
	cheap = current;
	while (current->next)
	{
		if (current->cost < cheap->cost)
			cheap = current;
		current = current->next;
	}
	if (cheap->cost != 0)
	{
		both_rotate_operations(data, cheap);
		rotate_operations(data, cheap);
		rev_rotate_operations(data, cheap);
	}
	push_b(data);
}

static void	send_b_to_a(t_data *data)
{
	t_stack	*cheap;
	t_stack	*current;

	set_index(data->stack_a);
	set_index(data->stack_b);
	set_targets_b(data->stack_a, data->stack_b);
	calc_cost_b(data->stack_a, data->stack_b);
	current = data->stack_b;
	cheap = current;
	while (current->next)
	{
		if (current->cost < cheap->cost)
			cheap = current;
		current = current->next;
	}
	if (cheap->cost != 0)
	{
		both_rotate_operations(data, cheap);
		rotate_operations(data, cheap);
		rev_rotate_operations(data, cheap);
	}
	push_a(data);
}

void	turk_sort(t_data *data)
{
	int	len;
	int	is_above_median;

	len = get_size(data->stack_a);
	if (len-- > 3 && !is_sorted(data->stack_a))
		push_b(data);
	if (len-- > 3 && !is_sorted(data->stack_a))
		push_b(data);
	while (len-- > 3)
		send_a_to_b(data);
	sort_three(data);
	len = get_size(data->stack_b);
	while (len-- > 0)
		send_b_to_a(data);
	set_index(data->stack_a);
	is_above_median = get_min(data->stack_a)->above_median;
	while (get_min(data->stack_a)->value != data->stack_a->value)
	{
		if (is_above_median == 1)
			rotate_a(data, 1);
		else
			rev_rotate_a(data, 1);
	}
}
