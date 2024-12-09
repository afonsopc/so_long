/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/09 22:45:29 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_mlx	**get_global_mlx(void)
{
	static t_mlx	*mlx;

	return (&mlx);
}

t_mlx	*global_mlx(void)
{
	return (*get_global_mlx());
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
}

int	init_mlx(int width, int height)
{
	t_mlx	*mlx;

	*get_global_mlx() = malloc(sizeof(t_mlx));
	if (!*get_global_mlx())
		return (0);
	mlx = *get_global_mlx();
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		return (free(mlx), 0);
	mlx->win = mlx_new_window(mlx->mlx, width, height, "So Long!");
	if (!(mlx->win))
		return (mlx_destroy_display(mlx->mlx), free(mlx), 0);
	return (1);
}

int	resize_window(int width, int height)
{
	t_mlx	*mlx;

	mlx = global_mlx();
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx->win = mlx_new_window(mlx->mlx, width, height, "So Long!");
	if (!(mlx->win))
		return (mlx_destroy_display(mlx->mlx), free(mlx), 0);
	return (1);
}
