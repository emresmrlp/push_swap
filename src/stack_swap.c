/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:44:58 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:32:58 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_a(t_data *data, int state)
{
	t_stack	*temp;

	if (!data->stack_a || !data->stack_a->next)
		return (1);
	temp = data->stack_a->next;
	if (temp->next)
	{
		data->stack_a->next = temp->next;
		temp->next->prev = data->stack_a;
	}
	else
		data->stack_a->next = NULL;
	data->stack_a->prev = temp;
	temp->next = data->stack_a;
	temp->prev = NULL;
	data->stack_a = temp;
	if (state)
		ft_printf("sa\n");
	return (0);
}
