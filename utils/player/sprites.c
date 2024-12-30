/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:45:04 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 03:10:55 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	append_left_sprites(t_sprite *sprite)
{
	t_sprite		*new_sprite;

	new_sprite = sprite_new("assets/player_open_left.png");
	if (!new_sprite)
		return (0);
	sprite_append(sprite, new_sprite);
	new_sprite = sprite_new("assets/player_close_left.png");
	if (!new_sprite)
		return (0);
	sprite_append(sprite, new_sprite);
	return (1);
}

int	append_up_sprites(t_sprite *sprite)
{
	t_sprite		*new_sprite;

	new_sprite = sprite_new("assets/player_open_up.png");
	if (!new_sprite)
		return (0);
	sprite_append(sprite, new_sprite);
	new_sprite = sprite_new("assets/player_close_up.png");
	if (!new_sprite)
		return (0);
	sprite_append(sprite, new_sprite);
	return (1);
}

int	append_down_sprites(t_sprite *sprite)
{
	t_sprite		*new_sprite;

	new_sprite = sprite_new("assets/player_open_down.png");
	if (!new_sprite)
		return (0);
	sprite_append(sprite, new_sprite);
	new_sprite = sprite_new("assets/player_close_down.png");
	if (!new_sprite)
		return (0);
	sprite_append(sprite, new_sprite);
	return (1);
}

int	init_player_sprites(t_player *player)
{
	t_sprite		*sprite;
	t_sprite		*new_sprite;

	sprite = sprite_new("assets/player_open_right.png");
	if (!sprite)
		return (0);
	new_sprite = sprite_new("assets/player_close_right.png");
	if (!new_sprite)
		return (free(sprite), 0);
	sprite_append(sprite, new_sprite);
	if (!append_left_sprites(sprite)
		|| !append_up_sprites(sprite)
		|| !append_down_sprites(sprite))
		return (free_sprites(sprite), 0);
	sprite_append(sprite, sprite);
	player->sprite = sprite;
	player->last_sprite_change_timestamp = get_time();
	return (1);
}
