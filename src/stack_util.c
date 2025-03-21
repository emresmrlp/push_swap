/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:25:32 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/20 08:10:13 by ysumeral         ###   ########.fr       */
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
	node->above_median = 0;
	node->cheapest = 0;
	node->cost = 0;
	node->ra = 0;
	node->rb = 0;
	node->rra = 0;
	node->rrb = 0;
	node->target = NULL;
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
	while (stack && stack->next)
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