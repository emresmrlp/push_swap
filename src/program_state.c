/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:01:17 by ysumeral          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:15 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	program_exit_with_error(t_data *data)
{
	memory_free(data);
	write(2, "Error\n", 6);
	exit(0);
	return (1);
}

int	program_exit(t_data *data)
{
	memory_free(data);
	exit(0);
	return (0);
}
