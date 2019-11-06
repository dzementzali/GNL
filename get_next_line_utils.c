/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:45:43 by dzementz          #+#    #+#             */
/*   Updated: 2019/11/05 14:37:13 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != c)
	{
		if (!str[i])
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*s;

	if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str2;

	if (!str || !*str || start > ((unsigned int)ft_strlen(str) + 1) || len == 0)
		return (ft_calloc(sizeof(char), 1));
	if (!(str2 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = (size_t)start;
	j = 0;
	while (str[i] && i < (len + start))
	{
		str2[j] = str[i];
		i++;
		j++;
	}
	if (str2)
		str2[j] = '\0';
	return (str2);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*str;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = 1;
	}
	if (!(str = malloc(size * count)))
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
