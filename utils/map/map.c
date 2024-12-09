/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:47:38 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 20:12:54 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	process_map(char *path)
{
	int				fd;

	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error("Invalid map file"), 0);
	if (!parse_map_file(fd, path))
		return (0);
	close(fd);
	return (1);
}
