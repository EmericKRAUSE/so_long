/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:22 by ekrause           #+#    #+#             */
/*   Updated: 2023/11/01 10:38:34 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst != NULL && del != NULL)
	{
		while (*lst)
		{
			temp = *lst;
			*lst = (*lst)->next;
			del(temp->content);
			free(temp);
		}
	}
}
