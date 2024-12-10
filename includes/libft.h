/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:56:49 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 22:39:40 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int				ft_count_occurrences(char *str, char to_count);
ssize_t			ft_putstr_fd(char *s, int fd);
ssize_t			ft_strlen(const char *s);
unsigned int	ft_abs(int n);
char			*ft_gnl(int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);

#endif