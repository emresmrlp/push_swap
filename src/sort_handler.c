/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:37:12 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/20 09:11:03 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_handler(t_data *data)
{
	if (data->size == 2)
		swap_a(data);
	else if (data->size == 3)
	 	sort_three(data);
	else
		sort_algorithm(data);
}