/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:11:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/09 21:15:02 by ysumeral         ###   ########.fr       */
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

    stack_a = *data->stack_a;
    stack_b = *data->stack_b;
    prepare_to_match_a(&stack_a, &stack_b);
    /*while (stack_a)
    {
        push_b(data);
        stack_a = stack_a->next;
    }*/
}

static void turksort_match_targets_b(t_data *data)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = *data->stack_a;
    stack_b = *data->stack_b;
    prepare_to_match_b(&stack_a, &stack_b);
    /*while (stack_b)
    {
        push_a(data);
        stack_b = stack_b->next;
    }*/
}

void sort_algorithm(t_data *data)
{
    int len;

    len = get_size(*data->stack_a);
    if (len-- > 3 && !is_sorted(data->stack_a))
        push_b(data);
    if (len-- > 3 && !is_sorted(data->stack_a))
        push_b(data);
    while (len-- > 3 && !is_sorted(data->stack_a))
        turksort_match_targets_a(data);
    sort_three(data);
    len = get_size(*data->stack_b);
    while (len--)
        turksort_match_targets_b(data);
    set_index(data->stack_a);
    min_to_top(data);
    //if (!is_sorted(data->stack_a))
    //    sort_algorithm(data);
}