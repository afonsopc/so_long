/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:31:11 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/06 17:46:55 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_object_list	*object_list_new(t_object *object)
{
	t_object_list	*object_list;

	object_list = malloc(sizeof(t_object_list));
	if (!object_list)
		return (NULL);
	object_list->object = object;
	object_list->next = NULL;
	return (object_list);
}

void	object_list_append(t_object_list *head, t_object_list *new)
{
	if (!new || !head)
		return ;
	while (head->next)
		head = head->next;
	head->next = new;
}
