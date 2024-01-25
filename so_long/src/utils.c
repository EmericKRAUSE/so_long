/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:48:40 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/25 13:23:14 by ekrause          ###   ########.fr       */
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

// t_list_wall	*ft_lstlast(t_list_wall	*lst)
// {
// 	t_list_wall	*temp;

// 	temp = NULL;
// 	if (lst != NULL)
// 	{
// 		temp = lst;
// 		while (temp-> next)
// 		{
// 			temp = temp-> next;
// 		}
// 	}
// 	return (temp);
// }

// void	ft_lstadd_back(t_list_wall **head, t_list_wall *node)
// {
// 	t_list_wall *last;
	
// 	if (!(*head))
// 		*head = node;
// 	else
// 	{
// 		last = ft_lstlast(*lst);
// 		last->next = node;
// 	}
// }

void	free_list(t_list_wall **head)
{
	t_list_wall	*previous;
	while (*head)
	{
		previous = *head;
		*head = (*head)->next;
		free (previous);
	}
}

void	print_list(t_list_wall *head)
{
	while (head)
	{
		printf ("%d / %d\n", head->y, head->x);
		head = head->next;
	}
}

t_list_wall	*create_node(t_list_wall *head, int y, int x)
{
	t_list_wall	*node;
	t_list_wall *current;

	node = malloc(sizeof(t_list_wall));
	if (!node)
		return NULL;
	node->y = y;
	node->x = x;
	node->next = NULL;
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
