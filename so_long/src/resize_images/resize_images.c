/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:24 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/14 14:46:21 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_images(void)
{
	resize_image_map();
	resize_image_trap();
	resize_image_exit();
	resize_image_ui();
	resize_image_player();
}
