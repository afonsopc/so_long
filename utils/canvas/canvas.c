/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 03:39:08 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

int	init_canvas(int width, int height)
{
	t_image		**canvas_ptr;
	t_image		*canvas;
	SDL_Surface	*canvas_surface;

	canvas_ptr = get_global_canvas();
	*canvas_ptr = malloc(sizeof(t_image));
	if (!*canvas_ptr)
		return (0);
	canvas = *canvas_ptr;
	canvas->width = width;
	canvas->height = height;
	canvas_surface = SDL_CreateRGBSurface(0, width, height,
			32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	if (!canvas_surface)
		return (free(canvas), 0);
	canvas->image = canvas_surface;
	return (1);
}

void	clear_canvas(void)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= global_canvas()->height)
	{
		x = -1;
		while (++x <= global_canvas()->width)
			put_pixel(global_canvas(), x, y, 0x000000);
	}
}

void	put_objects_in_canvas(t_object_list *object_list)
{
	while (object_list)
	{
		if (object_list->object->entity->active)
			put_image(
				object_list->object->entity
				->get_sprite((void *)object_list->object)->image,
				global_canvas(), object_list->object->entity->x,
				object_list->object->entity->y);
		object_list = object_list->next;
	}
}
