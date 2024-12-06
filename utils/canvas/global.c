/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:33:15 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/05 23:54:51 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_image	**get_global_canvas(void)
{
	static t_image	*canvas;

	return (&canvas);
}

t_image	*global_canvas(void)
{
	return (*get_global_canvas());
}
