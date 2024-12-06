/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:29:02 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 17:28:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	**get_global_map(void)
{
	static t_map	*map;

	return (&map);
}

t_map	*global_map(void)
{
	return (*get_global_map());
}
