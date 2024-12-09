/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:24:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/08 19:51:38 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	x_y_intercepts(int x1, int y1, int x2, int y2)
{
	return (x1 < x2 + SPRITE_WIDTH
		&& x1 + SPRITE_WIDTH > x2
		&& y1 < y2 + SPRITE_HEIGHT
		&& y1 + SPRITE_HEIGHT > y2);
}

int	check_wall_collision(int new_x, int new_y)
{
	t_object_list	*curr;

	curr = *global_object_list();
	while (curr)
	{
		if (curr->object->entity->type == 2 && x_y_intercepts(new_x, new_y,
				curr->object->entity->x, curr->object->entity->y))
			return (0);
		curr = curr->next;
	}
	return (1);
}

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
		else if (curr->object->entity->type == 4 && x_y_intercepts(player->entity->x,
				player->entity->y, curr->object->entity->x,
				curr->object->entity->y))
			exit_game();
		curr = curr->next;
	}
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
	process_other_collisions(this);
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
