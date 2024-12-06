/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 00:01:45 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_image(t_image	*image)
{
	mlx_destroy_image(global_mlx()->mlx, image->image);
	free(image);
}

t_image	*new_image_from_file(char	*path)
{
	t_image	*image;

	if (!path)
		return (NULL);
	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_xpm_file_to_image(global_mlx()->mlx, path,
			&image->width, &image->height);
	if (!image->image)
		return (free(image), NULL);
	return (image);
}

unsigned int	get_pixel(t_image *image, int x, int y)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data;
	char	*pixel;

	data = mlx_get_data_addr(image->image, &bits_per_pixel,
			&size_line, &endian);
	pixel = data + (y * size_line) + (x * (bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	put_pixel(t_image *image, int x, int y, unsigned int color)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data;
	char	*pixel;

	if (x < 0 || y < 0
		|| x >= image->width || y >= image->height)
		return ;
	data = mlx_get_data_addr(image->image, &bits_per_pixel,
			&size_line, &endian);
	pixel = data + (y * size_line) + (x * (bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	put_image(t_image *src, t_image *dst, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = -1;
	while (++i < src->width)
	{
		j = -1;
		while (++j < src->height)
		{
			color = get_pixel(src, i, j);
			if (color != 0xFF000000)
				put_pixel(dst, x + i, y + j, color);
		}
	}
}
