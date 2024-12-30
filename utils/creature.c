/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creature.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:55:00 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 17:55:01 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	creature_move(void *_this)
{
	t_creature		*this;

	this = (t_creature *)_this;
	if (get_time() - this->created_at < this->runaway_delay)
		return ;
	this->entity->x += 1;
}

t_sprite	*creature_get_sprite(void *_this)
{
	t_creature		*this;
	t_sprite		*sprite;

	this = (t_creature *)_this;
	if (!this->sprite)
		return (NULL);
	if (this->sprite_state)
		sprite = this->sprite->next;
	else
		sprite = this->sprite;
	if (get_time() - this->created_at >= this->runaway_delay)
		sprite = this->sprite->next;
	else if (get_time() - this->last_sprite_change_timestamp
		>= this->sprite_change_delay)
	{
		this->sprite_state = !this->sprite_state;
		this->last_sprite_change_timestamp = get_time();
	}
	return (sprite);
}

void	creature_free(void *_this)
{
	t_creature	*this;

	this = (t_creature *)_this;
	free_sprites(this->sprite);
	free(this->entity);
	free(this);
}

t_creature	*creature_new(int x, int y)
{
	t_creature	*creature;

	creature = ft_calloc(1, sizeof(t_creature));
	if (!creature)
		return (NULL);
	creature->sprite = sprite_new("assets/creature_left.png");
	if (!creature->sprite)
		return (free(creature), NULL);
	creature->sprite->next = sprite_new("assets/creature_right.png");
	if (!creature->sprite->next)
		return (free_sprites(creature->sprite), free(creature), NULL);
	sprite_append(creature->sprite, creature->sprite);
	creature->entity = entity_new(x, y);
	if (!creature->entity)
		return (free_sprites(creature->sprite), free(creature), NULL);
	creature->entity->move = creature_move;
	creature->entity->get_sprite = creature_get_sprite;
	creature->entity->free = creature_free;
	creature->entity->type = 5;
	creature->sprite_change_delay = 500;
	creature->last_sprite_change_timestamp = get_time();
	creature->runaway_delay = 5000;
	creature->created_at = get_time();
	return (creature);
}
