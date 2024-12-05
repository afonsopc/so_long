/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/05 22:48:54 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	init_player_sprites(t_player *player)
{
	struct timeval	current_time;
	t_sprite		*sprite;
	t_sprite		*new_sprite;

	sprite = sprite_new("assets/pagman.xpm");
	if (!sprite)
		return (0);
	new_sprite = sprite_new("assets/pagman_close.xpm");
	if (!new_sprite)
		return (free(sprite), 0);
	sprite_append(sprite, new_sprite);
	sprite_append(sprite, sprite);
	gettimeofday(&current_time, NULL);
	player->sprite = sprite;
	player->last_sprite_change = current_time;
	return (1);
}

int	init_player(void)
{
	t_player		**player_ptr;
	t_player		*player;

	player_ptr = get_global_player();
	*player_ptr = malloc(sizeof(t_player));
	if (!*player_ptr)
		return (0);
	player = *player_ptr;
	if (!init_player_sprites(player))
		return (free(player), 0);
	player->entity = entity_new();
	if (!player->entity)
		return (free_sprites(player->sprite), free(player), 0);
	player->entity->get_sprite = player_get_sprite;
	player->entity->move = player_move;
	player->move_up = 0;
	player->move_down = 0;
	player->move_left = 0;
	player->move_right = 0;
	player->points = 0;
	player->speed = 5;
	return (1);
}
