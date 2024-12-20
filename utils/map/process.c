/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:50:48 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 23:29:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	process_line(t_map_parse *parse)
{
	if (!checks_1(parse))
		return (0);
	if (parse->exits > 1)
		return (ft_error("More than one exit"), 0);
	if (parse->starting_positions > 1)
		return (ft_error("More than one starting position"), 0);
	if (!generate_objects(parse))
		return (0);
	return (1);
}

void	free_parse(t_map_parse *parse)
{
	free(parse->line);
	free(parse->prev_line);
	free_object_list(*global_object_list());
}

int	final_checks(t_map_parse *parse)
{
	return (check_exit(parse) && last_checks(parse)
		&& resize_window(parse->len * SPRITE_SIZE, parse->y * SPRITE_SIZE)
		&& init_canvas(parse->len * SPRITE_SIZE, parse->y * SPRITE_SIZE));
}

int	parse_map_file(int fd, char *path)
{
	t_map_parse	parse;

	parse.y = -1;
	parse.prev_line = NULL;
	parse.exits = 0;
	parse.starting_positions = 0;
	parse.path = path;
	while (++parse.y >= 0)
	{
		parse.line = ft_gnl(fd);
		if (!parse.line)
			break ;
		if (parse.line[ft_strlen(parse.line) - 1] == '\n')
			parse.line[ft_strlen(parse.line) - 1] = '\0';
		if (parse.y == 0)
			parse.len = ft_strlen(parse.line);
		if (!process_line(&parse))
			return (free_parse(&parse), 0);
		free(parse.prev_line);
		parse.prev_line = parse.line;
	}
	if (!final_checks(&parse))
		return (free_parse(&parse), 0);
	return (free(parse.line), free(parse.prev_line), 1);
}
