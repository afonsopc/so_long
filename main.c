/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:11:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/03 22:32:43 by afpachec         ###   ########.fr       */
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
	square(mlx, 200, 100, 300, 0xFFFFFF);
	square(mlx, -50, 100, 300, 0x0000FF);
	square(mlx, 200, 200, 100, 0xFF0000);
	square(mlx, 220, 220, 60, 0xFFFFFF);
	square(mlx, 245, 225, 10, 0x0000FF);
	square(mlx, 245, 245, 10, 0x0000FF);
	square(mlx, 245, 265, 10, 0x0000FF);
	square(mlx, 225, 245, 10, 0x0000FF);
	square(mlx, 245, 245, 10, 0x0000FF);
	square(mlx, 265, 245, 10, 0x0000FF);
	square(mlx, 285, 205, 10, 0xFFD70D);
	square(mlx, 265, 205, 10, 0xFFD70D);
	square(mlx, 245, 205, 10, 0xFFD70D);
	square(mlx, 225, 205, 10, 0xFFD70D);
	square(mlx, 205, 205, 10, 0xFFD70D);
	square(mlx, 285, 225, 10, 0xFFD70D);
	square(mlx, 285, 245, 10, 0xFFD70D);
	square(mlx, 285, 265, 10, 0xFFD70D);
	square(mlx, 285, 285, 10, 0xFFD70D);
	square(mlx, 285, 285, 10, 0xFFD70D);
	square(mlx, 265, 285, 10, 0xFFD70D);
	square(mlx, 245, 285, 10, 0xFFD70D);
	square(mlx, 225, 285, 10, 0xFFD70D);
	square(mlx, 205, 285, 10, 0xFFD70D);
	square(mlx, 205, 225, 10, 0xFFD70D);
	square(mlx, 205, 245, 10, 0xFFD70D);
	square(mlx, 205, 265, 10, 0xFFD70D);
	square(mlx, 205, 285, 10, 0xFFD70D);
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
