/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:28:23 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 19:35:07 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_gnl_strlen(char *str, char term)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] && str[counter] != term)
		counter++;
	if (str[counter] == '\n')
		counter++;
	return (counter);
}

static char	*ft_gnl_str_join_buff(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_gnl_strlen(s1, 0);
	s2_len = ft_gnl_strlen(s2, '\n');
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (free(s1), NULL);
	str[s1_len + s2_len] = '\0';
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len + i] = s2[i];
	free(s1);
	i = -1;
	while (s2[s2_len + ++i])
		s2[i] = s2[s2_len + i];
	s2[i] = '\0';
	return (str);
}

char	*ft_gnl(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buff[0])
		{
			line = ft_gnl_str_join_buff(line, buff);
			if (!line)
				return (NULL);
			if (line[ft_gnl_strlen(line, '\n') - 1] == '\n')
				break ;
		}
		else
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			buff[bytes_read] = '\0';
		}
	}
	return (line);
}
