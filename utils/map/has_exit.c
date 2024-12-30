/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:22:05 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 02:22:38 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	process_contagious_around(char **lines, int *touched_exit,
	t_x_and_y *x_y, t_x_and_y *size_x_y)
{
	if ((x_y->x > 0 && lines[x_y->y][x_y->x - 1] == 'P')
		|| (x_y->x < size_x_y->x - 1 && lines[x_y->y][x_y->x + 1] == 'P')
		|| (x_y->y > 0 && lines[x_y->y - 1][x_y->x] == 'P')
		|| (x_y->y < size_x_y->y - 1 && lines[x_y->y + 1][x_y->x] == 'P'))
	{
		if ((x_y->x > 0 && lines[x_y->y][x_y->x - 1] == 'E')
			|| (x_y->x < size_x_y->x - 1 && lines[x_y->y][x_y->x + 1] == 'E')
			|| (x_y->y > 0 && lines[x_y->y - 1][x_y->x] == 'E')
			|| (x_y->y < size_x_y->y - 1 && lines[x_y->y + 1][x_y->x] == 'E'))
			*touched_exit = 1;
		lines[x_y->y][x_y->x] = 'P';
		return (1);
	}
	return (0);
}

int	has_exit(char **lines, t_x_and_y *size_x_y)
{
	int			changed;
	int			touched_exit;
	t_x_and_y	x_y;

	touched_exit = 0;
	changed = 1;
	while (changed > 0)
	{
		changed = 0;
		x_y.y = -1;
		while (++x_y.y < size_x_y->y)
		{
			x_y.x = -1;
			while (++x_y.x < size_x_y->x)
			{
				if (lines[x_y.y][x_y.x] != '0' && lines[x_y.y][x_y.x] != 'C')
					continue ;
				changed += process_contagious_around(lines,
						&touched_exit, &x_y, size_x_y);
			}
		}
	}
	if (!still_has_food(lines) && touched_exit)
		return (1);
	return (0);
}

int	check_exit_loop(int fd, t_x_and_y *x_y, t_two_strs *strs)
{
	(*strs).str = ft_gnl(fd);
	if (!(*strs).str)
		return (0);
	(*strs).str2 = (*strs).str1;
	(*strs).str1 = malloc(((*x_y).y + 2) * sizeof(char *));
	(*x_y).x = -1;
	while (++(*x_y).x < (*x_y).y)
		(*strs).str1[(*x_y).x] = (*strs).str2[(*x_y).x];
	(*strs).str1[(*x_y).y] = (*strs).str;
	(*strs).str1[(*x_y).y + 1] = NULL;
	free((*strs).str2);
	(*x_y).y++;
	return (1);
}

void	free_two_strs(t_two_strs *strs)
{
	int	i;

	i = -1;
	while (strs->str1[++i])
		free(strs->str1[i]);
	free(strs->str1);
}

int	check_exit(t_map_parse *parse)
{
	t_x_and_y	x_y;
	t_two_strs	strs;
	int			fd;

	x_y.y = 0;
	fd = open(parse->path, O_RDONLY);
	if (fd < 0)
		return (0);
	strs.str1 = malloc(sizeof(char *));
	if (!strs.str1)
		return (close(fd), 0);
	strs.str1[0] = NULL;
	while (check_exit_loop(fd, &x_y, &strs))
		;
	close(fd);
	x_y.x = ft_strlen(strs.str1[0]);
	if (!has_exit(strs.str1, &x_y))
		return (ft_error("Doesnt have path to exit"), free_two_strs(&strs), 0);
	return (free_two_strs(&strs), 1);
}
