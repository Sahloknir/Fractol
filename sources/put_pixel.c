/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:11:29 by axbal             #+#    #+#             */
/*   Updated: 2018/03/11 11:59:12 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel_to_image(int x, int y, t_data *data, t_color color)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y < WIN_H)
	{
		IMG_STR[(x * BPP) + (y * S_L) + 0] = (char)color.b;
		IMG_STR[(x * BPP) + (y * S_L) + 1] = (char)color.g;
		IMG_STR[(x * BPP) + (y * S_L) + 2] = (char)color.r;
		IMG_STR[(x * BPP) + (y * S_L) + 3] = (char)color.alpha;
	}
}
