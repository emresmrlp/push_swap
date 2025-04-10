/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:19:13 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:32:48 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_node;
	t_stack	*target;

	while (stack_a)
	{
		target = NULL;
		current_node = stack_b;
		while (current_node)
		{
			if (current_node->value < stack_a->value)
			{
				if (target && target->value < current_node->value)
					target = current_node;
				else if (!target)
					target = current_node;
			}
			current_node = current_node->next;
		}
		if (!target)
			stack_a->target = get_max(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	set_targets_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_node;
	t_stack	*target;

	while (stack_b)
	{
		target = NULL;
		current_node = stack_a;
		while (current_node)
		{
			if (current_node->value > stack_b->value)
			{
				if (target && target->value > current_node->value)
					target = current_node;
				else if (!target)
					target = current_node;
			}
			current_node = current_node->next;
		}
		if (!target)
			stack_b->target = get_min(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}
