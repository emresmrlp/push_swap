/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:02:01 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:08 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicate(t_stack *stack)
{
	t_stack	*head;
	t_stack	*temp;

	head = stack;
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

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
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

int	get_size(t_stack *stack)
{
	int		i;
	t_stack	*temp;

	temp = stack;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
