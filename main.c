/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:11:08 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 16:43:20 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// return (write(1, "Hello from so_long :)\n", 22));

int	process_next_map(void)
{
	static int	map;
	char		*path;
	char		*tmp;
	char		*number;

	number = ft_itoa(map);
	if (!number)
		return (0);
	tmp = ft_strjoin("maps/", number);
	free(number);
	if (!tmp)
		return (0);
	path = ft_strjoin(tmp, ".ber");
	free(tmp);
	if (!path)
		return (0);
	if (!process_map(path))
		return (free(path), 0);
	map++;
	return (1);
}

void	game_loop(void)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			global_mlx()->over = 1;
		else if (event.type == SDL_KEYDOWN)
			key_press_frame(event.key.keysym.sym);
		else if (event.type == SDL_KEYUP)
			key_release_frame(event.key.keysym.sym);
	}
	if (global_mlx()->over)
	{
		free_object_list(*global_object_list());
		global_mlx()->over = 0;
		if (!process_next_map())
			return (ft_error("Map process"), exit_game());
	}
	frame();
}

int	main(void)
{
	if (!init_mlx(W_WIDTH, W_HEIGHT))
		return (ft_error("Mlx init"));
	emscripten_set_main_loop(game_loop, FRAME_TIME * 2.778, 1);
}
