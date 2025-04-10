/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:03:15 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:35:36 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	calc_reset(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		temp->ra = 0;
		temp->rb = 0;
		temp->rr = 0;
		temp->rrr = 0;
		temp->rra = 0;
		temp->rrb = 0;
		temp = temp->next;
	}
}

void	both_rotate_operations(t_data *data, t_stack *node)
{
	while (node->rr > 0)
	{
		rotate_rr(data);
		node->rr--;
	}
	while (node->rrr > 0)
	{
		rev_rotate_rrr(data);
		node->rrr--;
	}
}

void	rotate_operations(t_data *data, t_stack *cheap)
{
	while (cheap->ra > 0)
	{
		rotate_a(data, 1);
		if (cheap->ra)
			cheap->ra--;
		else
			break ;
	}
	while (cheap->rb > 0)
	{
		rotate_b(data, 1);
		if (cheap->rb)
			cheap->rb--;
		else
			break ;
	}
}

void	rev_rotate_operations(t_data *data, t_stack *cheap)
{
	while (cheap->rra && cheap->rra > 0)
	{
		rev_rotate_a(data, 1);
		if (cheap->rra)
			cheap->rra--;
		else
			break ;
	}
	while (cheap->rrb > 0)
	{
		rev_rotate_b(data, 1);
		if (cheap->rrb)
			cheap->rrb--;
		else
			break ;
	}
}
