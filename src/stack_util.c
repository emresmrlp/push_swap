/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:25:32 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 17:00:59 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack *node;

	node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_stack **stack, t_stack *node)
{
	t_stack *last_node;

	last_node = get_last_node(*stack);
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last_node->next = node;
	node->prev = last_node;
}

t_stack *get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	get_size(t_stack **stack)
{
	int i;
	t_stack *temp;

	temp = *stack;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}