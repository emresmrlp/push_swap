/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:03:14 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_index(t_stack *stack)
{
	int		i;
	int		median;
	int		size;
	t_stack	*temp;

	temp = stack;
	size = get_size(stack);
	median = size / 2;
	if (size % 2 != 0)
		median++;
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

void	min_to_top(t_data *data)
{
	t_stack	*min;

	min = data->stack_a;
	while (min->next)
		min = min->next;
	while (min->value != data->stack_a->value && min->above_median)
		rotate_a(data, 1);
	while (min->value != data->stack_a->value && !min->above_median)
		rev_rotate_a(data, 1);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
