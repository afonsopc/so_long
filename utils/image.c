/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/05 22:07:34 by afpachec         ###   ########.fr       */
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
