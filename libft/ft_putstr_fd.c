/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:47:32 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/02 23:33:01 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(nil)", 5));
	return (write(fd, s, ft_strlen(s)));
}
