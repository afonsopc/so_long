/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/04 19:26:56 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_canvas	**get_global_canvas(void)
{
	static t_canvas	*canvas;

	return (&canvas);
}

t_canvas	*global_canvas(void)
{
	return (*get_global_canvas());
}

int	init_canvas(void)
{
	t_canvas	**canvas_ptr;
	t_canvas	*canvas;
	void		*canvas_img;

	canvas_ptr = get_global_canvas();
	*canvas_ptr = malloc(sizeof(t_canvas));
	if (!*canvas_ptr)
		return (0);
	canvas = *canvas_ptr;
	canvas_img = mlx_new_image(global_mlx()->mlx, W_WIDTH, W_HEIGHT);
	if (!canvas_img)
		return (free(canvas), 0);
	canvas->canvas = canvas_img;
	return (1);
}

void	put_pixel(int x, int y, int color)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data;
	char	*pixel;

	pixel = NULL;
	data = mlx_get_data_addr(global_canvas()->canvas, &bits_per_pixel,
			&size_line, &endian);
	pixel = data + (y * size_line) + (x * (bits_per_pixel / 8));
	*(int *)pixel = color;
}
