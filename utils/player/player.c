/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 22:18:27 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	init_player_sprites(t_player *player)
{
	t_sprite		*sprite;
	t_sprite		*new_sprite;

	sprite = sprite_new("assets/player_open.xpm");
	if (!sprite)
		return (0);
	new_sprite = sprite_new("assets/player_close.xpm");
	if (!new_sprite)
		return (free(sprite), 0);
	sprite_append(sprite, new_sprite);
	sprite_append(sprite, sprite);
	player->sprite = sprite;
	player->last_sprite_change_timestamp = get_time();
	return (1);
}

void	free_player_ptr(t_player **player)
{
	free(*player);
	*player = NULL;
}

int	init_player(int x, int y)
{
	t_player		*player;

	*get_global_player() = malloc(sizeof(t_player));
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
	player->move_up = 0;
	player->move_down = 0;
	player->move_left = 0;
	player->move_right = 0;
	player->points = 0;
	player->speed = 2;
	player->moviment_count = 0;
	player->sprite_change_delay = 250;
	return (1);
}
