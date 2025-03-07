/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:44:58 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 17:34:33 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_a(t_data *data)
{
	t_stack **stack_a;
	t_stack **stack_b;
	t_stack	*node;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (!*stack_b)
		return (1);
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (!*stack_a)
		node->next = NULL;
	else
	{
		(*stack_a)->prev = node;
		node->next = *stack_a;
	}
	*stack_a = node;
	node->prev = NULL;
	ft_printf("pa\n");
	return (0);
}

int push_b(t_data *data)
{
	t_stack **stack_a;
	t_stack **stack_b;
	t_stack	*node;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (!*stack_a)
		return (1);
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (!*stack_b)
		node->next = NULL;
	else
	{
		(*stack_b)->prev = node;
		node->next = *stack_b;
	}
	*stack_b = node;
	node->prev = NULL;
	ft_printf("pb\n");
	return (0);
}
