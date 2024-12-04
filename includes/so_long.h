/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:18:25 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/04 21:22:30 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "mlx.h"

# ifndef W_HEIGHT
#  define W_HEIGHT 500
# endif

# ifndef KEY_W
#  define KEY_W 119
# endif

# ifndef KEY_A
#  define KEY_A 97
# endif

# ifndef KEY_S
#  define KEY_S 115
# endif

# ifndef KEY_D
#  define KEY_D 100
# endif

# ifndef W_WIDTH
#  define W_WIDTH 500
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_image
{
	void	*image;
	int		height;
	int		width;
}	t_image;

typedef struct s_sprite
{
	t_image	*image;
	void	*next;
}	t_sprite;

typedef struct s_player
{
	t_sprite		*sprite;
	int				height;
	int				width;
	void			(*move)();
	t_sprite		*(*get_sprite)();
	int				speed;
	int				x;
	int				y;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	struct timeval	last_sprite_change;
}	t_player;

typedef struct s_canvas
{
	void	*canvas;
}	t_canvas;

void		free_mlx(void);
void		put_pixel(int x, int y, int color);
t_mlx		*global_mlx(void);
ssize_t		ft_error(char *message);
int			init_mlx(void);
t_canvas	*global_canvas(void);
int			init_canvas(void);
t_player	*global_player(void);
t_image		*new_image_from_file(char	*path);
int			init_player(void);
t_sprite	*sprite_new(char	*path);
void		sprite_append(t_sprite	*head, t_sprite *new);

#endif