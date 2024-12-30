/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:49:46 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 03:15:48 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	set_sprite_direction(t_player *player)
{
	if (player->move_left)
		player->sprite_direction = LEFT;
	else if (player->move_up)
		player->sprite_direction = UP;
	else if (player->move_down)
		player->sprite_direction = DOWN;
	else if (player->move_right)
		player->sprite_direction = RIGHT;
}

t_sprite	*get_player_sprite(t_player *player)
{
	set_sprite_direction(player);
	if (player->sprite_direction == LEFT && player->sprite_state)
		return (player->sprite->next->next);
	else if (player->sprite_direction == LEFT)
		return (player->sprite->next->next->next);
	else if (player->sprite_direction == UP && player->sprite_state)
		return (player->sprite->next->next->next->next);
	else if (player->sprite_direction == UP)
		return (player->sprite->next->next->next->next->next);
	else if (player->sprite_direction == DOWN && player->sprite_state)
		return (player->sprite->next->next->next->next->next->next);
	else if (player->sprite_direction == DOWN)
		return (player->sprite->next->next->next->next->next->next->next);
	else if (player->sprite_state)
		return (player->sprite);
	else
		return (player->sprite->next);
}
