/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:11:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/03 22:50:27 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	square(t_mlx *mlx, int x, int y, int size, int color)
{
	int	tmp_y;
	int	tmp_x;

	tmp_y = y - 1;
	while (++tmp_y <= y + size)
	{
		tmp_x = x - 1;
		while (++tmp_x <= x + size)
			mlx_pixel_put(mlx->mlx, mlx->win, tmp_x, tmp_y, color);
	}
}

void	flag(t_mlx *mlx)
{
	square(mlx, 200, 0, 300, 0xFFFFFF);
	square(mlx, -50, 0, 300, 0x0000FF);
	square(mlx, 200, 100, 100, 0xFF0000);
	square(mlx, 220, 120, 60, 0xFFFFFF);
	square(mlx, 245, 125, 10, 0x0000FF);
	square(mlx, 245, 145, 10, 0x0000FF);
	square(mlx, 245, 165, 10, 0x0000FF);
	square(mlx, 225, 145, 10, 0x0000FF);
	square(mlx, 245, 145, 10, 0x0000FF);
	square(mlx, 265, 145, 10, 0x0000FF);
	square(mlx, 285, 105, 10, 0xFFD70D);
	square(mlx, 265, 105, 10, 0xFFD70D);
	square(mlx, 245, 105, 10, 0xFFD70D);
	square(mlx, 225, 105, 10, 0xFFD70D);
	square(mlx, 205, 105, 10, 0xFFD70D);
	square(mlx, 285, 125, 10, 0xFFD70D);
	square(mlx, 285, 145, 10, 0xFFD70D);
	square(mlx, 285, 165, 10, 0xFFD70D);
	square(mlx, 285, 185, 10, 0xFFD70D);
	square(mlx, 285, 185, 10, 0xFFD70D);
	square(mlx, 265, 185, 10, 0xFFD70D);
	square(mlx, 245, 185, 10, 0xFFD70D);
	square(mlx, 225, 185, 10, 0xFFD70D);
	square(mlx, 205, 185, 10, 0xFFD70D);
	square(mlx, 205, 125, 10, 0xFFD70D);
	square(mlx, 205, 145, 10, 0xFFD70D);
	square(mlx, 205, 165, 10, 0xFFD70D);
	square(mlx, 205, 185, 10, 0xFFD70D);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		return (ft_error("Invalid number of arguments"), 1);
	mlx = get_mlx();
	mlx = init_mlx();
	if (!mlx)
		return (ft_error("MLX initialization"), 1);
	flag(mlx);
	mlx_loop(mlx);
	(void)argv;
	return (write(1, "Hello from so_long :)\n", 22));
}
