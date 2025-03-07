/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:01:17 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/02 11:28:13 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	program_exit_with_error(t_data *data)
{
	memory_free(data);
	write(2, "Error\n", 6);
	return (1);
}

int	program_exit(t_data *data)
{
	memory_free(data);
	return (0);
}
