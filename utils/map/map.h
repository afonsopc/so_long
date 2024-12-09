/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:50:59 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 17:52:03 by afpachec         ###   ########.fr       */
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
	char			*path;
	int				starting_positions;
	t_object		*obj;
	t_object_list	*obj_list;
	ssize_t			len;
}	t_map_parse;

typedef struct s_x_and_y
{
	int	x;
	int	y;
}	t_x_and_y;

typedef struct s_two_strs
{
	char	**str1;
	char	**str2;
	char	*str;
}	t_two_strs;

int	generate_objects(t_map_parse *parse);
int	last_checks(t_map_parse *parse);
int	checks_1(t_map_parse *parse);
int	parse_map_file(int fd, char *path);
int	check_exit(t_map_parse *parse);

#endif