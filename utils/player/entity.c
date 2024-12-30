/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:24:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 17:54:47 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	process_other_collisions(t_player	*player)
{
	t_object_list	*curr;
	int				food_amount;

	food_amount = count_type_in_object_list(*global_object_list(), 3);
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
			&& global_player()->points == food_amount
			&& x_y_intercepts(player->entity->x,
				player->entity->y, curr->object->entity->x,
				curr->object->entity->y))
			global_mlx()->over = 1;
		curr = curr->next;
	}
}

int	get_speed(t_player *this)
{
	int	speed;

	if (count_type_in_object_list(*global_object_list(), 5) != 0)
		return (0);
	speed = (this->speed)
		+ ((get_time() - (this->last_move_timestamp)) / FRAME_TIME);
	this->last_move_timestamp = get_time();
	if (speed > SPRITE_SIZE / 2)
		return (SPRITE_SIZE / 2);
	if (this->sprinting)
		speed *= 2;
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
	sprite = get_player_sprite(this);
	if (get_time() - this->last_sprite_change_timestamp
		>= this->sprite_change_delay)
	{
		this->sprite_state = !this->sprite_state;
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
