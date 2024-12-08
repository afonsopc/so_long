/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:50:59 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/08 17:01:48 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../includes/so_long.h"

typedef struct map_parse
{
	char			*line;
	char			*prev_line;
	int				y;
	int				exits;
	int				starting_positions;
	t_object		*obj;
	t_object_list	*obj_list;
	ssize_t			len;
}	t_map_parse;

int	generate_objects(t_map_parse *parse);
int	last_checks(t_map_parse *parse);
int	checks_1(t_map_parse *parse);
int	parse_map_file(int fd);

#endif