/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 03:12:00 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	free_player_ptr(t_player **player)
{
	free(*player);
	*player = NULL;
}

int	init_player(int x, int y)
{
	t_player		*player;

	*get_global_player() = ft_calloc(1, sizeof(t_player));
	if (!*get_global_player())
		return (0);
	player = *get_global_player();
	if (!init_player_sprites(player))
		return (free_player_ptr(get_global_player()), 0);
	player->entity = entity_new(x, y);
	if (!player->entity)
		return (free_sprites(player->sprite),
			free_player_ptr(get_global_player()), 0);
	player->entity->get_sprite = player_get_sprite;
	player->entity->move = player_move;
	player->entity->free = player_free;
	player->entity->type = 1;
	player->speed = 1;
	player->sprite_change_delay = 250;
	player->last_move_timestamp = get_time();
	player->sprite_state = 0;
	player->sprite_direction = 0;
	return (1);
}
