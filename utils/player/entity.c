/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:24:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 23:19:36 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	process_other_collisions(t_player	*player)
{
	t_object_list	*curr;

	curr = *global_object_list();
	while (curr)
	{
		if (curr->object->entity->type == 3 && curr->object->entity->active
			&& x_y_intercepts(player->entity->x,
				player->entity->y, curr->object->entity->x,
				curr->object->entity->y))
		{
			global_player()->points++;
			curr->object->entity->active = 0;
		}
		else if (curr->object->entity->type == 4
			&& x_y_intercepts(player->entity->x,
				player->entity->y, curr->object->entity->x,
				curr->object->entity->y))
			exit_game();
		curr = curr->next;
	}
}

int	get_speed(t_player *this)
{
	int	speed;

	speed = (this->speed) + ((get_time() - (this->last_move_timestamp)) / 4);
	this->last_move_timestamp = get_time();
	if (speed > SPRITE_WIDTH / 2)
		return (SPRITE_WIDTH / 2);
	return (speed);
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
	s = get_speed(this);
	if (this->move_up)
		y -= s;
	if (this->move_down)
		y += s;
	process_wall_collision(&x, &y);
	if (this->move_left)
		x -= s;
	if (this->move_right)
		x += s;
	process_wall_collision(&x, &y);
	if (x != this->entity->x || y != this->entity->y)
		print_moviment_count(this);
	this->entity->x = x;
	this->entity->y = y;
	process_other_collisions(this);
}

t_sprite	*player_get_sprite(void *_this)
{
	t_sprite		*sprite;
	t_player		*this;

	this = (t_player *)_this;
	if (!this->sprite)
		return (NULL);
	sprite = this->sprite;
	if (get_time() - this->last_sprite_change_timestamp
		>= this->sprite_change_delay)
	{
		this->sprite = sprite->next;
		this->last_sprite_change_timestamp = get_time();
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
