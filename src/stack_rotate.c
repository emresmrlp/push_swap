/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:13:11 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 17:53:11 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rotate_a_algorithm(t_data *data)
{
	t_stack **stack_a;
	t_stack *first_node;
	t_stack *last_node;
	
	stack_a = data->stack_a;
	last_node = get_last_node(*stack_a);
	first_node = *stack_a;
	if (!first_node || last_node == first_node)
		return (1);
	*stack_a = first_node->next;
	(*stack_a)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
	return (0);
}

static int	rotate_b_algorithm(t_data *data)
{
	t_stack **stack_b;
	t_stack *first_node;
	t_stack *last_node;

	stack_b = data->stack_b;
	last_node = get_last_node(*stack_b);
	first_node = *stack_b;
	if (!first_node || last_node == first_node)
		return (1);
	*stack_b = first_node->next;
	(*stack_b)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
	return (0);
}

int rotate_a(t_data *data)
{
	if (rotate_a_algorithm(data))
		return (1);
	ft_printf("ra\n");
	return (0);
}

int rotate_b(t_data *data)
{
	if (rotate_b_algorithm(data))
		return (1);
	ft_printf("rb\n");
	return (0);
}

int rotate_ab(t_data *data)
{
	t_stack **stack_a;
	t_stack **stack_b;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (!stack_a || !stack_b || get_last_node(*stack_a) == *stack_a ||
		get_last_node(*stack_b) == *stack_b)
		return (1);
	rotate_a_algorithm(data);
	rotate_b_algorithm(data);
	ft_printf("rr\n");
	return (0);
}
