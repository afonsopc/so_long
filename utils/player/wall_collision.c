/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:43:25 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 21:48:05 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	set_wall_collision(t_wall_collision *wc, int x, int y)
{
	wc->wall_left = x;
	wc->wall_right = x + SPRITE_SIZE;
	wc->wall_top = y;
	wc->wall_bottom = y + SPRITE_SIZE;
}

void	set_push_direction(t_push_direction *pd, t_wall_collision *wc,
	int x, int y)
{
	pd->push_right = wc->wall_right - x;
	pd->push_left = wc->wall_left - (x + SPRITE_SIZE);
	pd->push_down = wc->wall_bottom - y;
	pd->push_up = wc->wall_top - (y + SPRITE_SIZE);
	pd->min_push = pd->push_right;
}

void	process_push_direction(t_push_direction *pd, int *x, int *y)
{
	if (ft_abs(pd->push_left) < ft_abs(pd->min_push))
		pd->min_push = pd->push_left;
	if (ft_abs(pd->push_up) < ft_abs(pd->min_push))
		pd->min_push = pd->push_up;
	if (ft_abs(pd->push_down) < ft_abs(pd->min_push))
		pd->min_push = pd->push_down;
	if (ft_abs(pd->min_push) == ft_abs(pd->push_left)
		|| ft_abs(pd->min_push) == ft_abs(pd->push_right))
		*x += pd->min_push;
	else
		*y += pd->min_push;
}

void	process_wall_collision(int *x, int *y)
{
	t_object_list		*curr;
	t_wall_collision	wc;
	t_push_direction	pd;

	curr = *global_object_list();
	while (curr)
	{
		if (curr->object->entity->type == 2)
		{
			set_wall_collision(&wc, curr->object->entity->x,
				curr->object->entity->y);
			if (*x + SPRITE_SIZE > wc.wall_left
				&& *x < wc.wall_right
				&& *y + SPRITE_SIZE > wc.wall_top
				&& *y < wc.wall_bottom)
				(set_push_direction(&pd, &wc, *x, *y),
					process_push_direction(&pd, x, y));
		}
		curr = curr->next;
	}
}
