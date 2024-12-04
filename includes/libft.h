/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:56:49 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/04 20:36:13 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

ssize_t			ft_putstr_fd(char *s, int fd);
ssize_t			ft_strlen(const char *s);
unsigned int	ft_abs(int n);

#endif