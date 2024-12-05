/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/05 22:20:42 by afpachec         ###   ########.fr       */
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
	return (sprite_new("assets/pt.xpm"));
}

t_entity	*entity_new(void)
{
	t_entity		*entity;

	entity = malloc(sizeof(t_entity));
	if (!entity)
		return (NULL);
	entity->get_sprite = default_get_sprite;
	entity->move = default_move;
	entity->x = 0;
	entity->y = 0;
	return (entity);
}
