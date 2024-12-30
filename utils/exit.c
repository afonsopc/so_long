/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:37:02 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 02:00:29 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(void)
{
	free_object_list(*global_object_list());
	free_image(global_canvas());
	free_mlx(global_mlx());
	exit(0);
}
