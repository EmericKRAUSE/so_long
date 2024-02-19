/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:19:40 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/01 10:19:12 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && n == 0)
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] && s1[i + j] == s2[j] && (i + j < n))
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
