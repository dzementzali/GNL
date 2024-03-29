/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:47:27 by dzementz          #+#    #+#             */
/*   Updated: 2019/11/05 19:36:32 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoinfree(char *s1, char *s2, int to_free)
{
	char		*vide;

	vide = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	ft_strcpy(vide, s1);
	ft_strcpy(vide + ft_strlen(s1), s2);
	if (to_free == 1 || to_free == 3)
		free(s1);
	if (to_free == 2 || to_free == 3)
		free(s2);
	return (vide);
}

int		get_next_line(int fd, char **line)
{
	static char		*stock = NULL;
	char			*buf;
	int				ret;
	int				i;

	if (fd < 0 || !line || (!(buf = ft_calloc(BUFF_SIZE + 1, sizeof(char)))))
		return (-1);
	stock = (!stock) ? (char *)ft_calloc(0, sizeof(char)) : stock;
	while (ft_strchr(buf, '\n') == 0 && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if ((ret == -1) || (buf[ret] = '\0'))
			return (-1);
		stock = ft_strjoinfree(stock, buf, 1);
	}
	free(buf);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	buf = stock;
	*line = ft_substr(stock, 0, i);
	stock = (*stock == '\0') ? NULL : ft_strdup(stock + i + 1);
	free(buf);
	if ((stock == NULL) && !ret && !ft_strlen(*line))
		free(stock);
	return (((stock == NULL) && !ret && !ft_strlen(*line)) ? 0 : 1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	line = NULL;
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d -> [%s]\n", i, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}
