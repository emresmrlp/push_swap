/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:51:18 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 08:29:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#       include <stdio.h>

static int param_conditions(char **av, int i)
{
	int j;
	
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
			{
				if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				{
					if (av[i][j + 1] == '\0' || !ft_isdigit(av[i][j + 1]))
						return (1);
				}
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int param_controls(t_data *data, int ac, char **av)
{
	int		i;

	i = 1;
	if (ac == 2)
	{
		data->buffer = ft_split(av[1], ' ');
		if (!data->buffer)
			return(1);
		av = data->buffer;
		i = 0;
	}
	if (param_conditions(av, i))
		return (1);
	return (0);
}
