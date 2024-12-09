/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:38:33 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 20:38:47 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	x_y_intercepts(int x1, int y1, int x2, int y2)
{
	return (x1 < x2 + SPRITE_WIDTH
		&& x1 + SPRITE_WIDTH > x2
		&& y1 < y2 + SPRITE_HEIGHT
		&& y1 + SPRITE_HEIGHT > y2);
}
