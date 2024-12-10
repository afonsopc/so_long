/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:38:33 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 20:38:47 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	print_moviment_count(t_player *this)
{
	this->moviment_count++;
	ft_putstr_fd("Moviment count: ", 1);
	ft_putnbr_fd(this->moviment_count, 1);
	ft_putstr_fd("\n", 1);
}
