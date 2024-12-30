/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:54:45 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/29 23:56:27 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	food_move(void *_this)
{
	(void)_this;
}

t_sprite	*food_get_sprite(void *_this)
{
	t_food	*this;

	this = (t_food *)_this;
	return (this->sprite);
}

void	food_free(void *_this)
{
	t_food	*this;

	this = (t_food *)_this;
	free_sprites(this->sprite);
	free(this->entity);
	free(this);
}

t_food	*food_new(int x, int y)
{
	t_food	*food;

	food = malloc(sizeof(t_food));
	if (!food)
		return (NULL);
	food->sprite = sprite_new("assets/food.png");
	if (!food->sprite)
		return (free(food), NULL);
	food->entity = entity_new(x, y);
	if (!food->entity)
		return (free_sprites(food->sprite), free(food), NULL);
	food->entity->move = food_move;
	food->entity->get_sprite = food_get_sprite;
	food->entity->free = food_free;
	food->entity->type = 3;
	return (food);
}
