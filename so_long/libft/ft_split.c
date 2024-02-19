/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:16:53 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/02 09:16:58 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char *s, char c)
{
	int	words;
	int	check;
	int	i;

	words = 0;
	check = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			check = 0;
		else if (!check)
		{
			check = 1;
			words++;
		}
		i++;
	}
	return (words);
}

static void	freesplit(char **result, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	**all(char *s, char **result, int words, char c)
{
	int	letter;
	int	i;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		letter = 0;
		while (s[letter] && s[letter] != c)
			letter++;
		result[i] = (char *)malloc(sizeof(char) * (letter + 1));
		if (!result[i])
		{
			freesplit(result, i);
			return (NULL);
		}
		letter = 0;
		while (*s && *s != c)
			result[i][letter++] = *s++;
		result[i++][letter] = '\0';
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = countwords((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	return (all((char *)s, result, words, c));
}
