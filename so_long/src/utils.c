/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:48:40 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/13 12:36:02 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

int	finder(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	free_list(t_list_component **head)
{
	t_list_component	*previous;

	while (*head)
	{
		previous = *head;
		*head = (*head)->next;
		free (previous);
	}
}

t_list_component	*create_node(t_list_component *head, \
int y, int x, char type)
{
	t_list_component	*node;
	t_list_component	*current;

	node = malloc(sizeof(t_list_component));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->y = y;
	node->x = x;
	node->type = type;
	if (!head)
		head = node;
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
	return (head);
}
