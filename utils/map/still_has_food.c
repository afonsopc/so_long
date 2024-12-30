/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   still_has_food.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:12:16 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 16:20:51 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	still_has_food(char **lines)
{
	int	x;
	int	y;

	y = -1;
	while (lines[++y])
	{
		x = -1;
		while (lines[y][++x])
		{
			if (lines[y][x] == 'C')
				return (1);
		}
	}
	return (0);
}
