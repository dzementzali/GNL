/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:54:39 by dzementz          #+#    #+#             */
/*   Updated: 2019/11/04 13:08:33 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#ifndef BUFF_SIZE
# define BUFF_SIZE 1
#endif

int get_next_line(int fd, char **line);
int	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcpy(char *dest, char *src);
char    *ft_strjoinfree(char *s1, char *s2, int to_free);

#endif
