/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:51:18 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 09:32:56 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	param_check_conditions(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
			{
				if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				{
					if (av[i][j + 1] == '\0' || !ft_isdigit(av[i][j + 1])
						|| av[i][j + 1] == '0')
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

static int	param_check_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		if (av[i + 1] == NULL)
		{
			if (i == 1)
				return (0);
			break ;
		}
		j = 1;
		while (av[j] != NULL)
		{
			if (!ft_strncmp(av[i], av[j], ft_strlen(av[i])) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	param_check_sorted(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (av[i + 1] == NULL)
		{
			if (i == 1)
				return (0);
			break ;
		}
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

static int	param_check_max_min(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	param_controls(t_data *data, int ac, char **av)
{
	if (ac == 2)
	{
		data->buffer = ft_split(av[1], ' ');
		if (!data->buffer)
			return (1);
		av = data->buffer;
	}
	if (param_check_conditions(av))
		return (1);
	if (param_check_duplicate(av))
		return (1);
	if (!param_check_sorted(av))
		return (0);
	if (param_check_max_min(av))
		return (1);
	return (0);
}
