/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/05 23:58:24 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	init_map(char *path)
{
	t_map		**map_ptr;
	t_map		*map;

	if (!path)
		return (0);
	(void)path;
	map_ptr = get_global_map();
	*map_ptr = malloc(sizeof(t_map));
	if (!*map_ptr)
		return (0);
	map = *map_ptr;
	if (!init_player(0, 0))
		return (free(map), 0);
	map->object_list = object_list_new((t_object *)global_player());
	if (!map->object_list)
		return (global_player()->entity->free((t_object *)global_player()),
			free(map), 0);
	return (1);
}
