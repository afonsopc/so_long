/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:27:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 21:48:28 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H

# define PLAYER_H
# include "../../includes/so_long.h"

typedef struct s_wall_collision
{
	int	wall_left;
	int	wall_right;
	int	wall_top;
	int	wall_bottom;
}	t_wall_collision;

typedef struct s_push_direction
{
	int	push_right;
	int	push_left;
	int	push_down;
	int	push_up;
	int	min_push;
}	t_push_direction;

void		player_move(void *_this);
t_sprite	*player_get_sprite(void *_this);
void		player_free(void *_this);
t_player	**get_global_player(void);
int			x_y_intercepts(int x1, int y1, int x2, int y2);
void		process_wall_collision(int *x, int *y);
void		print_moviment_count(t_player *this);

#endif