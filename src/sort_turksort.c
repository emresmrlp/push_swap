/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:11:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/20 09:10:14 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void prepare_to_match_a(t_stack **stack_a, t_stack **stack_b)
{
    set_index(stack_a);
    set_index(stack_b);
    set_targets_a(*stack_a, *stack_b);
    calc_cost_a(*stack_a, *stack_b);
}

static void prepare_to_match_b(t_stack **stack_a, t_stack **stack_b)
{
    set_index(stack_a);
    set_index(stack_b);
    set_targets_b(*stack_a, *stack_b);
    calc_cost_b(*stack_a, *stack_b);
}

static void turksort_match_targets_a(t_data *data)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *node;

    stack_a = *data->stack_a;
    stack_b = *data->stack_b;
    node = *data->stack_a;
    prepare_to_match_a(&stack_a, &stack_b);
    while (node && node->cheapest != 1)
        node = node->next;
    both_rotate_operations(data, node);
    rotate_operations(data, node);
    push_b(data);
}

static void turksort_match_targets_b(t_data *data)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *node;

    stack_a = *data->stack_a;
    stack_b = *data->stack_b;
    node = *data->stack_b;
    prepare_to_match_b(&stack_a, &stack_b);
    while (node && node->cheapest != 1)
        node = node->next;
    both_rotate_operations(data, node);
    rotate_operations(data, node);
    push_a(data);
}

void sort_algorithm(t_data *data)
{
    int len;

    len = get_size(data->stack_a);
    if (len-- > 3 && !is_sorted(data->stack_a))
        push_b(data);
    if (len-- > 3 && !is_sorted(data->stack_a))
        push_b(data);
    while (len-- > 3)
       turksort_match_targets_a(data);
    sort_three(data);
    len = get_size(data->stack_b);
    while (len--)
        turksort_match_targets_b(data);
    (void)turksort_match_targets_b;
    set_index(data->stack_a);
    min_to_top(data);
}
