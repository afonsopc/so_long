/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:54:45 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/29 23:56:29 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	wall_move(void *_this)
{
	(void)_this;
}

t_sprite	*wall_get_sprite(void *_this)
{
	t_wall	*this;

	this = (t_wall *)_this;
	return (this->sprite);
}

void	wall_free(void *_this)
{
	t_wall	*this;

	this = (t_wall *)_this;
	free_sprites(this->sprite);
	free(this->entity);
	free(this);
}

t_wall	*wall_new(int x, int y)
{
	t_wall	*wall;

	wall = malloc(sizeof(t_wall));
	if (!wall)
		return (NULL);
	wall->sprite = sprite_new("assets/wall.png");
	if (!wall->sprite)
		return (free(wall), NULL);
	wall->entity = entity_new(x, y);
	if (!wall->entity)
		return (free_sprites(wall->sprite), free(wall), NULL);
	wall->entity->move = wall_move;
	wall->entity->get_sprite = wall_get_sprite;
	wall->entity->free = wall_free;
	wall->entity->type = 2;
	return (wall);
}
