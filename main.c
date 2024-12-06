/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:11:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 23:07:10 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// return (write(1, "Hello from so_long :)\n", 22));

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Invalid number of arguments"));
	if (!init_mlx())
		return (ft_error("MLX initialization"));
	if (!init_canvas())
		return (free_mlx(), ft_error("Canvas initialization"));
	if (!load_map(argv[1]))
		return (free_canvas(), free_mlx(), ft_error("Map loading"));
	mlx_loop_hook(global_mlx()->mlx, frame, NULL);
	mlx_hook(global_mlx()->win, 3, 2, key_release_frame, NULL);
	mlx_hook(global_mlx()->win, 2, 3, key_press_frame, NULL);
	mlx_loop(global_mlx()->mlx);
}
