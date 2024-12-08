/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:11:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/08 20:08:07 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// return (write(1, "Hello from so_long :)\n", 22));

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Invalid number of arguments"));
	if (!init_mlx(W_WIDTH, W_HEIGHT))
		return (ft_error("Mlx init"));
	if (!process_map(argv[1]))
		return (free_mlx(global_mlx()), ft_error("Map load"));
	mlx_loop_hook(global_mlx()->mlx, frame, NULL);
	mlx_hook(global_mlx()->win, 3, 2, key_release_frame, NULL);
	mlx_hook(global_mlx()->win, 2, 3, key_press_frame, NULL);
	mlx_hook(global_mlx()->win, 17, 0, exit_game, NULL);
	mlx_loop(global_mlx()->mlx);
}
