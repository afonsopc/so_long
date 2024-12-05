/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:11:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/05 22:48:59 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	frame(void)
{
	t_object	*object;

	object = (t_object *)global_player();
	object->entity->move(object);
	mlx_put_image_to_window(global_mlx()->mlx, global_mlx()->win,
		global_canvas()->canvas, 0, 0);
	mlx_put_image_to_window(global_mlx()->mlx, global_mlx()->win,
		object->entity->get_sprite(object)->image->image,
		object->entity->x, object->entity->y);
	return (0);
}

int	key_press_frame(int key_code)
{
	if (key_code == KEY_W)
		global_player()->move_up = 1;
	if (key_code == KEY_A)
		global_player()->move_left = 1;
	if (key_code == KEY_S)
		global_player()->move_down = 1;
	if (key_code == KEY_D)
		global_player()->move_right = 1;
	return (0);
}

int	key_release_frame(int key_code)
{
	if (key_code == KEY_W)
		global_player()->move_up = 0;
	if (key_code == KEY_A)
		global_player()->move_left = 0;
	if (key_code == KEY_S)
		global_player()->move_down = 0;
	if (key_code == KEY_D)
		global_player()->move_right = 0;
	return (0);
}

// return (write(1, "Hello from so_long :)\n", 22));

void	draw_canvas(void)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= W_HEIGHT)
	{
		x = -1;
		while (++x <= W_WIDTH)
			put_pixel(x, y, 0xFFFFFF);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Invalid number of arguments"));
	if (!init_mlx())
		return (ft_error("MLX initialization"));
	if (!init_canvas())
		return (free_mlx(), ft_error("Canvas initialization"));
	if (!init_player())
		return (free_mlx(), ft_error("Player initialization"));
	draw_canvas();
	mlx_loop_hook(global_mlx()->mlx, frame, NULL);
	mlx_hook(global_mlx()->win, 3, 2, key_release_frame, NULL);
	mlx_hook(global_mlx()->win, 2, 3, key_press_frame, NULL);
	mlx_loop(global_mlx()->mlx);
	(void)argv;
}
