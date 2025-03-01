/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:24:27 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 11:30:33 by ysumeral         ###   ########.fr       */
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
	if (param_controls(data, ac, av))
		return (program_exit_with_error(data));
	if (param_count(data) == 1)
		return (program_exit(data));
	if (init(data))
		return (program_exit_with_error(data));
	if (stack_controls(data))
		return (program_exit_with_error(data));
	return (program_exit(data));
}
