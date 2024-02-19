/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:27:15 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/01 10:51:47 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	dstlen;
	char	*start_ptr;

	if (!s1 || !s2)
		return (NULL);
	dstlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(dstlen);
	if (!ptr)
		return (NULL);
	start_ptr = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (start_ptr);
}
