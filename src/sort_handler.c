/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:37:12 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/09 21:15:13 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	tester(t_data *data)
{
	t_stack *stack;

	ft_printf("--------------------\n");
	stack = *data->stack_a;
	while (stack)
	{
		if (stack->target)
			ft_printf("STACK A (%d): A.M. (%d), INDEX (%d), TARGET (%d)\n", stack->value, stack->above_median, stack->index, stack->target->value);
		else
			ft_printf("STACK A (%d): A.M. (%d), INDEX (%d), TARGET (NULL)\n", stack->value, stack->above_median, stack->index);
		stack = stack->next;
	}
	ft_printf("A SIZE: %d B SIZE: %d\n", get_size(*data->stack_a), get_size(*data->stack_b));
	stack = *data->stack_b;
	while (stack)
	{
		if (stack->target)
			ft_printf("STACK B (%d): A.M. (%d), INDEX (%d), TARGET (%d)\n", stack->value, stack->above_median, stack->index, stack->target->value);
		else
			ft_printf("STACK B (%d): A.M. (%d), INDEX (%d), TARGET (NULL)\n", stack->value, stack->above_median, stack->index);
		stack = stack->next;
	}
	ft_printf("--------------------\n");
}

void	sort_handler(t_data *data)
{
	if (data->size == 2)
		swap_a(data);
	else if (data->size == 3)
		sort_three(data);
	else
		sort_algorithm(data);
	tester(data);
}