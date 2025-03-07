/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:44:58 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 17:52:16 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	swap_a_algorithm(t_data *data)
{
	t_stack **stack_a;
	t_stack *first;
	t_stack *second;

	stack_a = data->stack_a;
	if (!*stack_a || !((*stack_a)->next))
		return (1);
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack_a = second;
	return (0);
}

static int	swap_b_algorithm(t_data *data)
{
	t_stack **stack_b;
	t_stack *first;
	t_stack *second;

	stack_b = data->stack_b;
	if (!*stack_b || !(*stack_b)->next)
		return (1);
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack_b = second;
	return (0);
}

int	swap_a(t_data *data)
{
	if (swap_a_algorithm(data))
		return (1);
	ft_printf("sa\n");
	return (0);
}

int	swap_b(t_data *data)
{
	if (swap_b_algorithm(data))
		return (1);
	ft_printf("sb\n");
	return (0);
}

int	swap_ab(t_data *data)
{
	t_stack **stack_a;
	t_stack **stack_b;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (!*stack_a || !*stack_b || !(*stack_a)->next || !(*stack_b)->next)
		return (1);
	swap_a(data);
	swap_b(data);
	ft_printf("ss\n");
	return (0);
}
