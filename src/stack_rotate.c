/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:13:11 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:00 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate_a(t_data *data, int state)
{
	t_stack	*bottom;
	t_stack	*top;

	if (!data->stack_a || !data->stack_a->next)
		return (1);
	bottom = data->stack_a;
	while (bottom->next)
		bottom = bottom->next;
	top = data->stack_a->next;
	bottom->next = data->stack_a;
	data->stack_a->prev = bottom;
	data->stack_a->next = NULL;
	data->stack_a = top;
	data->stack_a->prev = NULL;
	if (state)
		ft_printf("ra\n");
	return (0);
}

int	rotate_b(t_data *data, int state)
{
	t_stack	*bottom;
	t_stack	*top;

	if (!data->stack_b || !data->stack_b->next)
		return (1);
	bottom = data->stack_b;
	while (bottom->next)
		bottom = bottom->next;
	top = data->stack_b->next;
	bottom->next = data->stack_b;
	data->stack_b->prev = bottom;
	data->stack_b->next = NULL;
	data->stack_b = top;
	data->stack_b->prev = NULL;
	if (state)
		ft_printf("rb\n");
	return (0);
}

int	rotate_rr(t_data *data)
{
	if (!data->stack_a || !data->stack_b)
		return (1);
	if (!data->stack_a->next || !data->stack_b->next)
		return (1);
	rotate_a(data, 0);
	rotate_b(data, 0);
	ft_printf("rr\n");
	return (0);
}
