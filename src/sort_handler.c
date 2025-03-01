/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:37:12 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 18:03:55 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	tester(t_data *data)
{
	int	i;

	ft_printf("--------------------\n");
	i = 0;
	while (i < data->size_a)
	{
		ft_printf("STACK A (%d): %d\n", i, data->a[i]);
		i++;
	}
	ft_printf("A SIZE: %d B SIZE: %d\n", data->size_a, data->size_b);
	i = 0;
	while (i < data->size_b)
	{
		ft_printf("STACK B (%d): %d\n", i, data->b[i]);
		i++;
	}
	ft_printf("--------------------\n");
}

void	sort(t_data *data)
{
	tester(data);
	if (data->size == 2)
		swap_a(data);
	else if (data->size == 3)
		sort_three(data);
	else if (data->size == 4)
		sort_four(data);
	else if (data->size == 5)
		sort_five(data);
	else
		sort_large(data);
	tester(data);
}