/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:18:09 by axbal             #+#    #+#             */
/*   Updated: 2018/03/22 13:54:07 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_burningship(float c_r, float c_i, t_data *data)
{
	int			iter;
	float		tmp;
	float		z_r;
	float		z_i;
	int			x;
	int			y;

	x = c_r;
	y = c_i;
	c_r = x / ZOOM + X_MIN;
	c_i = y / ZOOM + Y_MIN;
	iter = 0;
	z_r = 0;
	z_i = 0;
	while (iter < MAX_ITER && z_r * z_r + z_i * z_i < 4)
	{
		tmp = z_r;
		z_r = absolute_val(z_r * z_r - z_i * z_i + c_r);
		z_i = absolute_val(2 * z_i * tmp + c_i);
		iter++;
	}
	if (iter == MAX_ITER)
		put_pixel_to_image(x, y, data, COLORS[0]);
	else
		put_pixel_to_image(x, y, data, COLORS[1 + (iter % NB_COLORS)]);
}

void	burn_pos(int mode, t_data *data)
{
	if (mode == 1)
	{
		X_MIN = -2.1;
		X_MAX = 1.2;
		Y_MIN = -2.05;
		Y_MAX = 1.25;
		ZOOM = WIN_W / (X_MAX - X_MIN);
	}
	else
		ZOOM = WIN_W / (X_MAX - X_MIN);
}

void	burningship(int mode, t_data *data)
{
	int		x;
	int		y;

	if (mode < 3)
		burn_pos(mode, data);
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			draw_burningship(x, y, data);
			x++;
		}
		y++;
	}
}
