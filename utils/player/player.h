/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:27:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 17:55:53 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H

# define PLAYER_H
# include "../../includes/so_long.h"

void		player_move(void *_this);
t_sprite	*player_get_sprite(void *_this);
void		player_free(void *_this);
t_player	**get_global_player(void);

#endif