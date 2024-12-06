/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/05 23:57:30 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

int	init_canvas(void)
{
	t_image	**canvas_ptr;
	t_image	*canvas;
	void	*canvas_img;

	canvas_ptr = get_global_canvas();
	*canvas_ptr = malloc(sizeof(t_image));
	if (!*canvas_ptr)
		return (0);
	canvas = *canvas_ptr;
	canvas->width = W_WIDTH;
	canvas->height = W_HEIGHT;
	canvas_img = mlx_new_image(global_mlx()->mlx,
			canvas->width, canvas->height);
	if (!canvas_img)
		return (free(canvas), 0);
	canvas->image = canvas_img;
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
			put_pixel(global_canvas(), x, y, 0xFFFFFF);
	}
}
