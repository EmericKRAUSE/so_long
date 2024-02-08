/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:48:40 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/08 13:34:02 by ekrause          ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen((char *)src);
	if (!dest || !src || size == 0)
		return (srclen);
	while (*src && --size)
		*dest++ = *src++;
	*dest = '\0';
	return (srclen);
}

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_convert_tostr(int n, char *str)
{
	int	i;
	int	len;

	len = ft_intlen(n);
	i = 1;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (n > 0)
	{
		str[len - i] = n % 10 + 48;
		n /= 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!str)
		return (NULL);
	ft_convert_tostr(n, str);
	return (str);
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
