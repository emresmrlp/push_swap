/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:06:56 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:18 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->above_median = 0;
	node->cost = 0;
	node->ra = 0;
	node->rb = 0;
	node->rr = 0;
	node->rrr = 0;
	node->rra = 0;
	node->rrb = 0;
	node->target = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static int	init_stacks(t_data *data)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*temp;

	i = 1;
	stack_a = create_node(ft_atol(data->buffer[0]));
	data->stack_a = stack_a;
	data->stack_b = NULL;
	while (data->buffer[i] != NULL)
	{
		temp = create_node(ft_atol(data->buffer[i]));
		temp->prev = stack_a;
		stack_a->next = temp;
		stack_a = temp;
		i++;
	}
	return (0);
}

int	program_init(t_data *data)
{
	if (init_stacks(data))
		return (1);
	return (0);
}
