/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:56:44 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/08 16:56:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_object	*get_object_from_char(char c, int x, int y)
{
	t_object	*obj;

	if (c == 'P' && init_player(x * SPRITE_SIZE,
			y * SPRITE_SIZE))
		obj = (t_object *)global_player();
	else if (c == '1')
		obj = (t_object *)wall_new(x * SPRITE_SIZE,
				y * SPRITE_SIZE);
	else if (c == 'C')
		obj = (t_object *)food_new(x * SPRITE_SIZE,
				y * SPRITE_SIZE);
	else if (c == 'E')
		obj = (t_object *)exit_place_new(x * SPRITE_SIZE,
				y * SPRITE_SIZE);
	else
		obj = NULL;
	return (obj);
}

int	generate_objects(t_map_parse *parse)
{
	int				i;

	i = -1;
	while (parse->line[++i])
	{
		parse->obj = get_object_from_char(parse->line[i], i, parse->y);
		parse->obj_list = NULL;
		if (parse->line[i] == '0')
			continue ;
		else if (!parse->obj)
			return (ft_error("Object node invalid"), 0);
		parse->obj_list = object_list_new((t_object *)parse->obj);
		if (!parse->obj_list)
			return (parse->obj->entity->free((void *)parse->obj),
				ft_error("Object list node invalid"), 0);
		object_list_append(global_object_list(), parse->obj_list);
	}
	return (1);
}
