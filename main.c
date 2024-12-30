/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:11:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/29 22:22:21 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// return (write(1, "Hello from so_long :)\n", 22));

void	game_loop(void)
{
	SDL_Event	event;
	int			running;

	running = 1;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
			else if (event.type == SDL_KEYDOWN)
				key_press_frame(event.key.keysym.sym);
			else if (event.type == SDL_KEYUP)
				key_release_frame(event.key.keysym.sym);
		}
		frame();
		SDL_RenderPresent(global_mlx()->mlx);
	}
	exit_game();
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Invalid number of arguments"));
	if (!init_mlx(W_WIDTH, W_HEIGHT))
		return (ft_error("Mlx init"));
	if (!process_map(argv[1]))
		return (free_mlx(global_mlx()), ft_error("Map load"));
	game_loop();
}
