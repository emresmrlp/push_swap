/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:11:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/16 23:24:13 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void prepare_to_match_a(t_stack **stack_a, t_stack **stack_b)
{
    set_index(stack_a);
    set_index(stack_b);
    set_targets_a(*stack_a, *stack_b);
    set_cheapest_a(*stack_a, *stack_b);
}

static void prepare_to_match_b(t_stack **stack_a, t_stack **stack_b)
{
    set_index(stack_a);
    set_index(stack_b);
    set_targets_b(*stack_a, *stack_b);
    set_cheapest_b(*stack_a, *stack_b);
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
    while (node)
    {
        if (node->cheapest)
        {
            while (node->index != 0 && node->cost > 0)
            {
                if (stack_a->next && stack_a->next == node)
                    swap_a(data);
                else if (node->above_median)
                    rotate_a(data);
                else
                    rev_rotate_a(data);
                set_index(data->stack_a);
                node->cost--;
            }
            while (stack_b->index != stack_a->target->index && node->cost > 0)
            {
                if (stack_b->next && stack_b->next->index == stack_a->target->index)
                    swap_b(data);
                else if (stack_b->above_median)
                    rotate_b(data);
                else
                    rev_rotate_b(data);
                node->cost--;
            }
            push_b(data);
            break ;
        }
        node = node->next;
    }
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
    while (node)
    {
        if (node->cheapest)
        {
            while (node->index != 0 && node->cost > 0)
            {
                if (node->above_median)
                    rotate_b(data);
                else
                    rev_rotate_b(data);
                set_index(data->stack_b);
                node->cost--;
            }
            while (stack_a->index != stack_b->target->index && node->cost > 0)
            {
                if (stack_b->target->above_median)
                    rotate_a(data);
                else
                    rev_rotate_a(data);
                node->cost--;
            }
            push_a(data);
            break ;
        }

        node = node->next;
    }
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
    set_index(data->stack_a);
    min_to_top(data);
}
