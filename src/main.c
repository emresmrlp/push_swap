/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:24:27 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/07 17:54:07 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;
	
	if (ac < 2)
		return (1);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (program_exit_with_error(data));
	data->stack_a = NULL;
	data->stack_b = NULL;
	if (param_controls(data, ac, av))
		return (program_exit_with_error(data));
	if (data->size == 1)
		return (program_exit(data));
	if (program_init(data))
		return (program_exit_with_error(data));
	if (stack_controls(data))
		return (program_exit_with_error(data));
	if (is_sorted(data->stack_a))
		return (program_exit(data));
	sort_handler(data);
	return (program_exit(data));
}
