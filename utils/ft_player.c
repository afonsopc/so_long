/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/04 20:37:33 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_player	**get_global_player(void)
{
	static t_player	*player;

	return (&player);
}

t_player	*global_player(void)
{
	return (*get_global_player());
}

void	move(void)
{
	if (global_player()->move_up)
		global_player()->y -= global_player()->speed;
	if (global_player()->move_down)
		global_player()->y += global_player()->speed;
	if (global_player()->move_left)
		global_player()->x -= global_player()->speed;
	if (global_player()->move_right)
		global_player()->x += global_player()->speed;
}

t_sprite	*get_sprite(void)
{
	t_sprite		*sprite;
	struct timeval	current_time;

	if (!global_player()->sprite)
		return (NULL);
	gettimeofday(&current_time, NULL);
	sprite = global_player()->sprite;
	if (ft_abs(current_time.tv_usec - global_player()->last_sprite_change.tv_usec) >= 200000)
	{
		global_player()->sprite = sprite->next;
		global_player()->last_sprite_change = current_time;
	}
	return (sprite);
}

int	init_player(void)
{
	t_player		**player_ptr;
	t_player		*player;
	t_sprite		*sprite;
	t_sprite		*new_sprite;
	struct timeval	current_time;

	player_ptr = get_global_player();
	*player_ptr = malloc(sizeof(t_player));
	if (!*player_ptr)
		return (0);
	player = *player_ptr;
	sprite = sprite_new("assets/pagman.xpm");
	if (!sprite)
		return (free(player), 0);
	new_sprite = sprite_new("assets/pagman_close.xpm");
	if (!new_sprite)
		return (free(player), free(sprite), 0);
	sprite_append(sprite, new_sprite);
	sprite_append(sprite, sprite);
	gettimeofday(&current_time, NULL);
	player->x = 0;
	player->y = 0;
	player->move_up = 0;
	player->move_down = 0;
	player->move_left = 0;
	player->move_right = 0;
	player->speed = 5;
	player->move = move;
	player->sprite = sprite;
	player->last_sprite_change = current_time;
	player->get_sprite = get_sprite;
	return (1);
}
