/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:24:27 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 08:15:01 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (program_exit_with_error(data));
	if (init(data))
		return (program_exit_with_error(data));
	if (param_controls(data, ac, av))
		return (program_exit_with_error(data));
	return (0);
}
