/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:10 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 01:36:10 by afpachec         ###   ########.fr       */
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
	if (!mlx)
		return ;
	if (mlx->win)
		SDL_DestroyWindow(mlx->win);
	if (mlx->mlx)
		SDL_DestroyRenderer(mlx->mlx);
	SDL_Quit();
	free(mlx);
}

int	init_mlx(int width, int height)
{
	t_mlx	*mlx;

	*get_global_mlx() = malloc(sizeof(t_mlx));
	if (!*get_global_mlx())
		return (0);
	mlx = *get_global_mlx();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (free(mlx), 0);
	mlx->win = SDL_CreateWindow("So Long!", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (!(mlx->win))
		return (SDL_Quit(), free(mlx), 0);
	mlx->mlx = SDL_CreateRenderer(mlx->win, -1, SDL_RENDERER_SOFTWARE);
	if (!(mlx->mlx))
		return (SDL_DestroyWindow(mlx->win), SDL_Quit(), free(mlx), 0);
	global_mlx()->over = 1;
	return (1);
}

int	resize_window(int width, int height)
{
	t_mlx	*mlx;

	mlx = global_mlx();
	SDL_SetWindowSize(mlx->win, width, height);
	return (1);
}
