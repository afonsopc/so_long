/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:31:11 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/08 16:18:36 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_object_list	**global_object_list(void)
{
	static t_object_list	*object_list;

	return (&object_list);
}

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

void	object_list_append(t_object_list **head, t_object_list *new)
{
	t_object_list	*tmp;

	if (!new || !head)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_object_list(t_object_list *object_list)
{
	t_object_list	*next;

	while (object_list)
	{
		next = object_list->next;
		object_list->object->entity->free((void *)object_list->object);
		free(object_list);
		object_list = next;
	}
}
