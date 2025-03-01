/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:03:41 by ysumeral          #+#    #+#             */
/*   Updated: 2025/03/01 10:28:09 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	word_len;
	size_t	i;

	i = 0;
	buffer = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (ft_strchr(s, c) == NULL)
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			buffer[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	buffer[i] = NULL;
	return (buffer);
}
