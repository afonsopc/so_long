/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:49:55 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/29 23:56:23 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_place_move(void *_this)
{
	(void)_this;
}

t_sprite	*exit_place_get_sprite(void *_this)
{
	t_exit_place	*this;

	this = (t_exit_place *)_this;
	return (this->sprite);
}

void	exit_place_free(void *_this)
{
	t_exit_place	*this;

	this = (t_exit_place *)_this;
	free_sprites(this->sprite);
	free(this->entity);
	free(this);
}

t_exit_place	*exit_place_new(int x, int y)
{
	t_exit_place	*exit_place;

	exit_place = malloc(sizeof(t_exit_place));
	if (!exit_place)
		return (NULL);
	exit_place->sprite = sprite_new("assets/door.png");
	if (!exit_place->sprite)
		return (free(exit_place), NULL);
	exit_place->entity = entity_new(x, y);
	if (!exit_place->entity)
		return (free_sprites(exit_place->sprite), free(exit_place), NULL);
	exit_place->entity->move = exit_place_move;
	exit_place->entity->get_sprite = exit_place_get_sprite;
	exit_place->entity->free = exit_place_free;
	exit_place->entity->type = 4;
	return (exit_place);
}
