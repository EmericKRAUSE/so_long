/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:48:40 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/29 15:02:01 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *str)
{
	printf("Error :\n%s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_strchr(char *str, char to_find)
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	print_list(t_list_component	*head)
{
	while (head)
	{
		printf ("%d / %c\n", head->nb, head->type);
		head = head->next;
	}
}

t_list_component	*create_node(t_list_component *head, int y, int x, char type)
{
	t_list_component	*node;
	t_list_component	*current;

	node = malloc(sizeof(t_list_component));
	if (!node)
		return NULL;
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

void	add_data_to_node(t_game *game)
{
	t_list_component	*temp;
	int	c;

	temp = game->list_component;
	c = 0;
	while (temp)
	{
		if (temp->type == 'C')
			temp->nb = c++;
		else
			temp->nb = 0;
		temp = temp->next;
	}
}

