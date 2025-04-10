/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:44:58 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:05 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_a(t_data *data)
{
	t_stack	*top;

	if (!data->stack_b)
		return (1);
	top = data->stack_a;
	data->stack_a = data->stack_b;
	data->stack_b = data->stack_b->next;
	if (data->stack_b)
		data->stack_b->prev = NULL;
	data->stack_a->next = top;
	if (top)
		top->prev = data->stack_a;
	data->stack_a->prev = NULL;
	ft_printf("pa\n");
	return (0);
}

int	push_b(t_data *data)
{
	t_stack	*top;

	if (!data->stack_a)
		return (1);
	top = data->stack_b;
	data->stack_b = data->stack_a;
	data->stack_a = data->stack_a->next;
	if (data->stack_a)
		data->stack_a->prev = NULL;
	data->stack_b->next = top;
	if (top)
		top->prev = data->stack_b;
	data->stack_b->prev = NULL;
	ft_printf("pb\n");
	return (0);
}
