/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:06:12 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/08 20:09:33 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_objects(t_object_list *object_list)
{
	while (object_list)
	{
		object_list->object->entity->move((void *)object_list->object);
		object_list = object_list->next;
	}
}

int	frame(void)
{
	clear_canvas();
	put_objects_in_canvas(*global_object_list());
	move_objects(*global_object_list());
	mlx_put_image_to_window(global_mlx()->mlx, global_mlx()->win,
		global_canvas()->image, 0, 0);
	return (0);
}

int	key_press_frame(int key_code)
{
	if (!global_player())
		return (0);
	if (key_code == KEY_W)
		global_player()->move_up = 1;
	if (key_code == KEY_A)
		global_player()->move_left = 1;
	if (key_code == KEY_S)
		global_player()->move_down = 1;
	if (key_code == KEY_D)
		global_player()->move_right = 1;
	if (key_code == KEY_ESC)
		exit_game();
	return (0);
}

int	key_release_frame(int key_code)
{
	if (!global_player())
		return (0);
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
