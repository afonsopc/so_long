/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:46:14 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/02 23:31:11 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *message)
{
	if (!message)
		return (error("Is this Nierlicious or DIVINE intelect?"));
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}
