/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 00:36:20 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_image(t_image *image)
{
	if (!image)
		return ;
	if (image->image)
		SDL_FreeSurface(image->image);
	free(image);
}

t_image	*new_image_from_file(char *path)
{
	t_image		*image;
	SDL_Surface	*surface;
	SDL_Surface	*optimized_surface;

	if (!path)
		return (NULL);
	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	surface = IMG_Load(path);
	if (!surface)
		return (free(image), NULL);
	optimized_surface = SDL_ConvertSurfaceFormat(surface,
			SDL_PIXELFORMAT_RGBA8888, 0);
	SDL_FreeSurface(surface);
	if (!optimized_surface)
		return (free(image), NULL);
	image->image = optimized_surface;
	image->width = optimized_surface->w;
	image->height = optimized_surface->h;
	return (image);
}

unsigned int	get_pixel(t_image *image, int x, int y)
{
	return (((Uint32 *)image->image->pixels)[(y * image->image->w) + x]);
}

void	put_pixel(t_image *image, int x, int y, unsigned int color)
{
	Uint32	*pixels;

	pixels = (Uint32 *)image->image->pixels;
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	pixels[(y * image->image->w) + x] = color;
}

void	put_image(t_image *src, t_image *dst, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < src->height)
	{
		j = 0;
		while (j < src->width)
		{
			color = get_pixel(src, j, i);
			if (color != 0xFF000000)
				put_pixel(dst, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
