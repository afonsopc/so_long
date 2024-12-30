/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/29 23:56:20 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	default_move(void *this)
{
	(void)this;
	ft_error("move() not implemented.");
}

t_sprite	*default_get_sprite(void *this)
{
	(void)this;
	ft_error("get_sprite() not implemented. (could cause leaks)");
	return (sprite_new("assets/pt.png"));
}

void	default_free(void *this)
{
	(void)this;
	ft_error("free() not implemented. (could cause leaks)");
}

t_entity	*entity_new(int x, int y)
{
	t_entity		*entity;

	entity = malloc(sizeof(t_entity));
	if (!entity)
		return (NULL);
	entity->get_sprite = default_get_sprite;
	entity->move = default_move;
	entity->free = default_free;
	entity->x = x;
	entity->y = y;
	entity->active = 1;
	return (entity);
}
