/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occurrences.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:43:22 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/07 22:44:51 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_occurrences(char *str, char to_count)
{
	int	occurrences;

	occurrences = 0;
	while (str && *str)
	{
		if (*str == to_count)
			occurrences++;
		str++;
	}
	return (occurrences);
}
