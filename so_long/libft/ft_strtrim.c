/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:03:06 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/01 10:57:46 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getend(const char *s1, const char *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i])
	{
		if (!ft_strchr(set, s1[len - i - 1]))
			return (len - i);
		len--;
	}
	return (len - i);
}

static int	getstart(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*ptr;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = getstart(s1, set);
	end = getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	ptr = malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
