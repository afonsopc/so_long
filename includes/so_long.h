/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:18:25 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 23:07:07 by afpachec         ###   ########.fr       */
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

typedef struct s_entity
{
	void			(*move)(void *this);
	t_sprite		*(*get_sprite)(void *this);
	void			(*free)(void *this);
	int				x;
	int				y;
}	t_entity;

typedef struct s_player
{
	t_entity		*entity;
	t_sprite		*sprite;
	int				speed;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				points;
	struct timeval	last_sprite_change;
}	t_player;

typedef struct s_object
{
	t_entity			*entity;
}	t_object;

typedef struct s_object_list
{
	t_object				*object;
	struct s_object_list	*next;
}	t_object_list;

t_image			*new_image_from_file(char	*path);
void			sprite_append(t_sprite	*head, t_sprite *new);
ssize_t			ft_error(char *message);
void			clear_canvas(void);
t_object_list	*object_list_new(t_object *object);
void			object_list_append(t_object_list *head, t_object_list *new);
int				load_map(char *path);

void			free_sprites(t_sprite *sprite);
void			free_image(t_image	*image);
void			free_mlx(void);
void			free_canvas(void);

t_image			*global_canvas(void);
t_player		*global_player(void);
t_mlx			*global_mlx(void);
t_object_list	**global_object_list(void);

t_sprite		*sprite_new(char	*path);
t_entity		*entity_new(int x, int y);

int				init_canvas(void);
int				init_player(int x, int y);
int				init_mlx(void);

unsigned int	get_pixel(t_image *image, int x, int y);
void			put_pixel(t_image *image, int x, int y, unsigned int color);
void			put_image(t_image *src, t_image *dst, int x, int y);
void			put_objects_in_canvas(t_object_list *object_list);

int				frame(void);
int				key_press_frame(int key_code);
int				key_release_frame(int key_code);

#endif