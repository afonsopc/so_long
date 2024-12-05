/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:29:02 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/05 21:29:12 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	**get_global_player(void)
{
	static t_player	*player;

	return (&player);
}

t_player	*global_player(void)
{
	return (*get_global_player());
}
