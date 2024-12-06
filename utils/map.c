/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:47:38 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 22:59:37 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_map(char *path)
{
	t_object_list	**object_list;

	(void)path;
	if (!init_player(0, 0))
		return (0);
	object_list = global_object_list();
	*object_list = object_list_new((t_object *)global_player());
	if (!*object_list)
		return (global_player()->entity->free((void *)global_player()), 0);
	return (1);
}
