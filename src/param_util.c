/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:09:43 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 12:10:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	param_count(char **av)
{
    int i;

    i = 0;
    while (av[i] != NULL)
        i++;
    return (i);
}