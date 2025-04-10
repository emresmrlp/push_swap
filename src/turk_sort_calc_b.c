/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_calc_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:39:23 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:32:54 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	calc_b_cheap_to_top(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

	current = stack_b;
	while (current)
	{
		if (current->above_median)
			current->rb = current->index;
		else
			current->rrb = get_size(stack_b) - current->index;
		if (current->target->above_median)
			current->ra = current->target->index;
		else
			current->rra = get_size(stack_a) - current->target->index;
		current->cost = current->ra + current->rb
			+ current->rra + current->rrb;
		current = current->next;
	}
}

static void	calc_b_rr_and_rrr(t_stack *stack_b)
{
	t_stack	*current;

	current = stack_b;
	while (current)
	{
		while (current->ra > 0 && current->rb > 0)
		{
			current->rr++;
			current->ra--;
			current->rb--;
			current->cost--;
		}
		while (current->rra > 0 && current->rrb > 0)
		{
			current->rrr++;
			current->rra--;
			current->rrb--;
			current->cost--;
		}
		current = current->next;
	}
}

void	calc_cost_b(t_stack *stack_a, t_stack *stack_b)
{
	calc_reset(stack_b);
	calc_b_cheap_to_top(stack_a, stack_b);
	calc_b_rr_and_rrr(stack_a);
}
