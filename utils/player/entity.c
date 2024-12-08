/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:24:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/08 17:00:41 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	check_wall_collision(int new_x, int new_y)
{
	t_object_list	*curr;

	curr = *global_object_list();
	while (curr)
	{
		if (curr->object->entity->type == 2
			&& new_x < curr->object->entity->x + SPRITE_WIDTH
			&& new_x + SPRITE_WIDTH > curr->object->entity->x
			&& new_y < curr->object->entity->y + SPRITE_HEIGHT
			&& new_y + SPRITE_HEIGHT > curr->object->entity->y)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	player_move(void *_this)
{
	t_player		*this;
	int				x;
	int				y;
	int				s;

	this = (t_player *)_this;
	x = this->entity->x;
	y = this->entity->y;
	s = this->speed;
	if (this->move_up && check_wall_collision(x, y - s))
		this->entity->y -= s;
	if (this->move_down && check_wall_collision(x, y + s))
		this->entity->y += s;
	if (this->move_left && check_wall_collision(x - s, y))
		this->entity->x -= s;
	if (this->move_right && check_wall_collision(x + s, y))
		this->entity->x += s;
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
