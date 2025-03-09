/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:19:13 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/09 21:47:33 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void calc_costs_a(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_a;
    (void)stack_b;
    ft_printf("calc_costs_a\n");
}

static void calc_costs_b(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_a;
    (void)stack_b;
    ft_printf("calc_costs_b\n");
}

void set_cheapest_a(t_stack *stack_a, t_stack *stack_b)
{
    calc_costs_a(stack_a, stack_b);
    ft_printf("set_cheapest_a\n");
}

void set_cheapest_b(t_stack *stack_a, t_stack *stack_b)
{
    calc_costs_b(stack_a, stack_b);
    ft_printf("set_cheapest_b\n");
}
