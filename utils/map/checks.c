/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:57:37 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/30 02:35:53 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	checks_1(t_map_parse *parse)
{
	int	i;

	if (parse->len != ft_strlen(parse->line))
		return (ft_error("Length of line is different than first"), 0);
	if (parse->y == 0 && ft_count_occurrences(parse->line, '1') != parse->len)
		return (ft_error("First line is not only walls"), 0);
	i = 0;
	while (parse->line[i])
	{
		if (parse->line[i] != '1' && parse->line[i] != '0'
			&& parse->line[i] != 'P' && parse->line[i] != 'E'
			&& parse->line[i] != 'C' && parse->line[i] != 'R')
			return (ft_error("Invalid character in map"), 0);
		if (parse->line[i] == 'P')
			parse->starting_positions++;
		if (parse->line[i] == 'E' || parse->line[i] == 'R')
			parse->exits++;
		i++;
	}
	if (parse->starting_positions > 1)
		return (ft_error("More than one starting position"), 0);
	return (1);
}

int	last_checks(t_map_parse *parse)
{
	if (parse->exits == 0)
		return (ft_error("No exit"), 0);
	if (parse->starting_positions == 0)
		return (ft_error("No starting position"), 0);
	if (ft_count_occurrences(parse->prev_line, '1') != parse->len)
		return (ft_error("Last line is not only walls"), 0);
	return (1);
}
