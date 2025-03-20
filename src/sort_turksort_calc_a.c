/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort_calc_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:39:23 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/20 09:06:30 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void calc_reset(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_a)
    {
        stack_a->ra = 0;
        stack_a->rb = 0;
        stack_a->rra = 0;
        stack_a->rrb = 0;
        stack_a = stack_a->next;
    }
    while (stack_b)
    {
        stack_b->ra = 0;
        stack_b->rb = 0;
        stack_b->rra = 0;
        stack_b->rrb = 0;
        stack_b = stack_b->next;
    }
}

static void calc_place_to_top(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;

	current = stack_a;
	while (current)
	{
		if (current->above_median)
			current->ra = current->index;
		else
			current->rra = get_size(&stack_a) - current->index;
		if (current->target->above_median)
			current->rb += current->target->index;
		else
			current->rrb += get_size(&stack_b) - current->target->index;
		current = current->next;
	}
}

static void calc_rr_and_rrr(t_stack *stack_a)
{
    t_stack *current;
    int rr;
    int rrr;

    current = stack_a;
    while (current)
    {
        rr = 0;
        rrr= 0;
        while (current->ra > 0 && current->rb > 0)
        {
            rr++;
            current->ra--;
            current->rb--;
        }
        while (current->rra > 0 && current->rrb > 0)
        {
            rrr++;
            current->rra--;
            current->rrb--;
        }
        current->cost = rr + rrr + current->ra + current->rb
            + current->rra + current->rrb;
        current = current->next;
    }
}

static void set_cheapest_a(t_stack *stack_a)
{
	t_stack *current;
	t_stack *cheapest;

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

void calc_cost_a(t_stack *stack_a, t_stack *stack_b)
{
    calc_reset(stack_a, stack_b);
    calc_place_to_top(stack_a, stack_b);
    calc_rr_and_rrr(stack_a);
    set_cheapest_a(stack_a);
}
