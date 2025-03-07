/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:11:09 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 16:50:59 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int check_duplicate(t_stack **stack)
{
	t_stack *head;
	t_stack *temp;

	head = *stack;
	while (head)
	{
		temp = head->next;
		while (temp)
		{
			if (head->value == temp->value)
				return (1);
			temp = temp->next;
		}
		head = head->next;
	}
	return (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	if (!temp)
		return (1);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	stack_controls(t_data *data)
{
	if (check_duplicate(data->stack_a))
		return (1);
	return (0);
}
