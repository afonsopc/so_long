/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/04 19:38:00 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	*sprite_new(char	*path)
{
	t_sprite	*sprite;

	if (!path)
		return (NULL);
	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->image = new_image_from_file(path);
	if (!sprite->image)
		return (free(sprite), NULL);
	sprite->next = NULL;
	return (sprite);
}

void	sprite_append(t_sprite	*head, t_sprite *new)
{
	if (!new || !head)
		return ;
	while (head->next)
		head = head->next;
	head->next = new;
}
