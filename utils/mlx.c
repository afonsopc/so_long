/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/04 19:25:08 by afpachec         ###   ########.fr       */
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

void	free_mlx(void)
{
	mlx_destroy_window(global_mlx()->mlx, global_mlx()->win);
	mlx_destroy_display(global_mlx()->mlx);
	free(global_mlx());
}

int	init_mlx(void)
{
	t_mlx	**mlx_ptr;
	t_mlx	*mlx;

	mlx_ptr = get_global_mlx();
	*mlx_ptr = malloc(sizeof(t_mlx));
	if (!*mlx_ptr)
		return (0);
	mlx = *mlx_ptr;
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		return (free(mlx), 0);
	mlx->win = mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT, "So Long!");
	if (!(mlx->win))
		return (mlx_destroy_display(mlx->mlx), free(mlx), 0);
	return (1);
}
