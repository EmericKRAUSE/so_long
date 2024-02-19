/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:01:31 by event             #+#    #+#             */
/*   Updated: 2023/10/24 15:23:57 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*a;
	const char	*b;

	if (src == dst)
		return (dst);
	a = (char *)dst;
	b = (const char *)src;
	if (a < b)
	{
		while (len--)
			*a++ = *b++;
	}
	else
	{
		while (len--)
			a[len] = b[len];
	}
	return ((char *)dst);
}
