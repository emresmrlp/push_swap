/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:51:18 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/02 07:32:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	param_check_conditions(char **av)
{
	int	i;
	int	j;

	i = 0;
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

static int	param_allocation(t_data *data, int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		data->buffer = ft_split(av[1], ' ');
		if (!data->buffer)
			return (1);
	}
	else
	{
		i = 0;
		data->buffer = (char **)ft_calloc(ac, sizeof(char *));
		while (av[i + 1] != NULL)
		{
			data->buffer[i] = ft_strdup(av[i + 1]);
			if (!data->buffer[i])
				return (1);
			i++;
		}
		data->buffer[i] = NULL;
	}
	return (0);
}

static int	param_check_max_min(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	param_count(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (i);
}

int	param_controls(t_data *data, int ac, char **av)
{
	if (param_allocation(data, ac, av))
		return (1);
	data->size = param_count(data->buffer);
	if (param_check_max_min(data->buffer))
		return (1);
	if (param_check_conditions(data->buffer))
		return (1);
	return (0);
}
