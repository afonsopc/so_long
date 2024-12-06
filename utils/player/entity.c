/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:24:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 17:55:33 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_move(void *_this)
{
	t_player		*this;

	this = (t_player *)_this;
	if (this->move_up)
		this->entity->y -= this->speed;
	if (this->move_down)
		this->entity->y += this->speed;
	if (this->move_left)
		this->entity->x -= this->speed;
	if (this->move_right)
		this->entity->x += this->speed;
}

t_sprite	*player_get_sprite(void *_this)
{
	t_sprite		*sprite;
	struct timeval	current_time;
	t_player		*this;

	this = (t_player *)_this;
	if (!this->sprite)
		return (NULL);
	gettimeofday(&current_time, NULL);
	sprite = this->sprite;
	if (ft_abs(current_time.tv_usec
			- this->last_sprite_change.tv_usec) >= 200000)
	{
		this->sprite = sprite->next;
		this->last_sprite_change = current_time;
	}
	return (sprite);
}

void	player_free(void *_this)
{
	t_player		*this;

	this = (t_player *)_this;
	free_sprites(this->sprite);
	free(this->entity);
	free(this);
}
