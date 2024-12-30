/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:18:25 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 17:55:22 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <emscripten/emscripten.h>

# ifndef FRAME_TIME
#  define FRAME_TIME 16.67
# endif

# ifndef W_HEIGHT
#  define W_HEIGHT 500
# endif

# ifndef KEY_ESC
#  define KEY_ESC 27
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

# ifndef KEY_SHIFT
#  define KEY_SHIFT 1073742049
# endif

# ifndef W_WIDTH
#  define W_WIDTH 1040
# endif

# ifndef SPRITE_SIZE
#  define SPRITE_SIZE 40
# endif

typedef struct s_mlx
{
	SDL_Renderer	*mlx;
	void			*win;
	int				over;
}	t_mlx;

typedef struct s_image
{
	SDL_Surface	*image;
	int			height;
	int			width;
}	t_image;

typedef struct s_sprite
{
	t_image			*image;
	struct s_sprite	*next;
}	t_sprite;

typedef struct s_entity
{
	void			(*move)(void *this);
	t_sprite		*(*get_sprite)(void *this);
	void			(*free)(void *this);
	int				type;
	int				active;
	int				x;
	int				y;
}	t_entity;

typedef enum e_sprite_direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}	t_sprite_direction;

typedef struct s_player
{
	t_entity			*entity;
	t_sprite			*sprite;
	int					speed;
	int					move_up;
	int					move_down;
	int					move_left;
	int					move_right;
	int					sprite_change_delay;
	int					moviment_count;
	int					sprite_state;
	int					sprinting;
	t_sprite_direction	sprite_direction;
	int					points;
	time_t				last_move_timestamp;
	time_t				last_sprite_change_timestamp;
}	t_player;

typedef struct s_wall
{
	t_entity		*entity;
	t_sprite		*sprite;
}	t_wall;

typedef struct s_food
{
	t_entity		*entity;
	t_sprite		*sprite;
}	t_food;

typedef struct s_creature
{
	t_entity		*entity;
	t_sprite		*sprite;
	time_t			created_at;
	time_t			last_sprite_change_timestamp;
	time_t			runaway_delay;
	int				sprite_state;
	int				sprite_change_delay;
}	t_creature;

typedef struct s_exit_place
{
	t_entity		*entity;
	t_sprite		*sprite;
}	t_exit_place;

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
void			object_list_append(t_object_list **head, t_object_list *new);
int				process_map(char *path);
int				resize_window(int width, int height);
time_t			get_time(void);
int				count_type_in_object_list(t_object_list *object_list, int type);

void			free_sprites(t_sprite *sprite);
void			free_image(t_image	*image);
void			free_mlx(t_mlx *mlx);
void			free_object_list(t_object_list *object_list);

void			exit_game(void);

t_image			*global_canvas(void);
t_player		*global_player(void);
t_mlx			*global_mlx(void);
t_object_list	**global_object_list(void);

t_sprite		*sprite_new(char	*path);
t_entity		*entity_new(int x, int y);
t_wall			*wall_new(int x, int y);
t_food			*food_new(int x, int y);
t_exit_place	*exit_place_new(int x, int y);
t_creature		*creature_new(int x, int y);

int				init_canvas(int width, int height);
int				init_player(int x, int y);
int				init_mlx(int width, int height);

unsigned int	get_pixel(t_image *image, int x, int y);
void			put_pixel(t_image *image, int x, int y, unsigned int color);
void			put_image(t_image *src, t_image *dst, int x, int y);
void			put_objects_in_canvas(t_object_list *object_list);

int				frame(void);
int				key_press_frame(int key_code);
int				key_release_frame(int key_code);

#endif