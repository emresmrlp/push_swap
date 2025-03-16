/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:19:13 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/16 09:44:21 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void calc_costs_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;

	current = stack_a;
	while (current)
	{
		if (current->above_median)
			current->cost = current->index;
		else
			current->cost = get_size(&stack_a) - current->index;
		if (current->target->above_median)
			current->cost += current->target->index;
		else
			current->cost += get_size(&stack_b) - current->target->index;
		current = current->next;
	}
}

static void calc_costs_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;
	
	current = stack_b;
	while (current)
	{
		if (current->above_median)
			current->cost = current->index;
		else
			current->cost = get_size(&stack_b) - current->index;
		if (current->target->above_median)
			current->cost += current->target->index;
		else
			current->cost += get_size(&stack_a) - current->target->index;
		current = current->next;
	}
}

void set_cheapest_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;
	t_stack *cheapest;

	calc_costs_a(stack_a, stack_b);
	current = stack_a;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	cheapest->cheapest = 1;
}

void set_cheapest_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;
	t_stack *cheapest;

	calc_costs_b(stack_a, stack_b);
	current = stack_b;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	cheapest->cheapest = 1;
}
