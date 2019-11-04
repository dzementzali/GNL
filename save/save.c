/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:47:27 by dzementz          #+#    #+#             */
/*   Updated: 2019/10/29 18:38:22 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	// substr --pour define le start et longueur de la chain de char --
	// strchr --pour le /n--
	// join --pour cree la chaine de char a stocker dans buf--
	// 
	static char *stock;
	char buf[BUFF_SIZE + 1];
	int ret;
	int i;

	i = 0;
	if (BUFF_SIZE <= 0)
		return (0);
	if (!stock)
		stock = malloc(sizeof(char) * 0);
	printf("stock avant boucle :\n%s\n", stock);
	while ((ft_strchr(stock, '\n') == 0) && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0'; 
		stock = ft_strjoin(stock, buf);
		printf("stock dans la boucle :\n%s\n", stock);
	}
	while (stock[i] && stock[i] != '\n')
		i++;
	*line = ft_substr(stock, 0, i);
	*stock = *stock + ft_strlen(*line) + 1;	
	printf("stock sortie de boucle :\n%s\n", stock);
	printf("line sortie de boucle :\n%s\n", *line);
	return (ret);
}

/*int main(int ac, char **av)
  {
  int fd;
  char *str;


  str = malloc(sizeof(char) * BUFF_SIZE);
  fd = open(av[1], O_RDONLY);
  printf("fd : %d\n", fd);
  printf("ret : %d\n", get_next_line(fd, &str));


  }*/

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int fd = open(av[1], O_RDONLY);
	char	*line = NULL;
	int		i = 0;

	while (get_next_line(fd, &line) > 5)
	{
		printf("%d => %s\n", i, line);
		i++;
		free(line);
	}	
	close(fd);
	return (0);
}
