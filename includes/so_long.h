/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:18:25 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/03 22:18:44 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

t_mlx	*get_mlx(void);
void	ft_error(char *message);
t_mlx	*init_mlx(void);

#endif