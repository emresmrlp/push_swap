/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:11:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 21:21:38 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void prepare_to_match_a(t_data *data)
{
    set_index(data->stack_a);
    set_index(data->stack_b);
}

static void prepare_to_match_b(t_data *data)
{
    set_index(data->stack_a);
    set_index(data->stack_b);
}

static void match_target_a(t_data *data)
{
    prepare_to_match_a(data);
}

static void match_target_b(t_data *data)
{
    prepare_to_match_b(data);
}

void sort_algorithm(t_data *data)
{
    int len;

    len = get_size(data->stack_a);
    if (len-- > 3 && !is_sorted(data->stack_a))
        push_b(data);
    if (len-- > 3 && !is_sorted(data->stack_a))
        push_b(data);
    while (len-- > 3 && !is_sorted(data->stack_a))
        match_target_a(data);
    sort_three(data);
    len = get_size(data->stack_b);
    while (len--)
        match_target_b(data);
    set_index(data->stack_a);
    min_to_top(data);
}