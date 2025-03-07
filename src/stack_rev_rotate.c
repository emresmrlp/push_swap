/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:23:24 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 17:52:24 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rev_rotate_a_algorithm(t_data *data)
{
	t_stack **stack_a;
	t_stack *first_node;
	t_stack *last_node;

	stack_a = data->stack_a;
	last_node = get_last_node(*stack_a);
	if (!*stack_a || last_node == *stack_a)
		return (1);
	first_node = *stack_a;
	*stack_a = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	return (0);
}

static int	rev_rotate_b_algorithm(t_data *data)
{
	t_stack **stack_b;
	t_stack *first_node;
	t_stack *last_node;

	stack_b = data->stack_b;
	last_node = get_last_node(*stack_b);
	if (!*stack_b || last_node == *stack_b)
		return (1);
	first_node = *stack_b;
	*stack_b = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	return (0);
}

int	rev_rotate_a(t_data *data)
{
	if (rev_rotate_a_algorithm(data))
		return (1);
	ft_printf("rra\n");
	return (0);
}

int rev_rotate_b(t_data *data)
{
	if (rev_rotate_b_algorithm(data))
		return (1);
	ft_printf("rrb\n");
	return (0);
}

int	rev_rotate_ab(t_data *data)
{
	t_stack **stack_a;
	t_stack **stack_b;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	if (!*stack_a || !*stack_b || get_last_node(*stack_a) == *stack_a
		|| get_last_node(*stack_b) == *stack_b)
		return (1);
	rev_rotate_a_algorithm(data);
	rev_rotate_b_algorithm(data);
	ft_printf("rrr\n");
	return (0);
}
