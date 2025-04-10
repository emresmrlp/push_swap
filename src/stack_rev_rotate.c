/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:23:24 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:03 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rev_rotate_a(t_data *data, int state)
{
	t_stack	*top;

	if (!data->stack_a || !data->stack_a->next)
		return (1);
	top = data->stack_a;
	while (top->next)
		top = top->next;
	top->prev->next = NULL;
	top->prev = NULL;
	top->next = data->stack_a;
	data->stack_a->prev = top;
	data->stack_a = top;
	if (state)
		ft_printf("rra\n");
	return (0);
}

int	rev_rotate_b(t_data *data, int state)
{
	t_stack	*top;

	if (!data->stack_b || !data->stack_b->next)
		return (1);
	top = data->stack_b;
	while (top->next)
		top = top->next;
	top->prev->next = NULL;
	top->prev = NULL;
	top->next = data->stack_b;
	data->stack_b->prev = top;
	data->stack_b = top;
	if (state)
		ft_printf("rrb\n");
	return (0);
}

int	rev_rotate_rrr(t_data *data)
{
	if (!data->stack_a || !data->stack_b)
		return (1);
	if (!data->stack_a->next || !data->stack_b->next)
		return (1);
	rev_rotate_a(data, 0);
	rev_rotate_b(data, 0);
	ft_printf("rrr\n");
	return (0);
}
