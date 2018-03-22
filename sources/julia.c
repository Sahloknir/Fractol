/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:22:49 by axbal             #+#    #+#             */
/*   Updated: 2018/03/22 17:07:15 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_julia(float x, float y, t_data *data)
{
	int			iter;
	float		tmp;
	float		z_r;
	float		z_i;

	z_r = x / ZOOM + X_MIN;
	z_i = y / ZOOM + Y_MIN;
	iter = 0;
	while (iter < MAX_ITER && z_r * z_r + z_i * z_i < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + J_R;
		z_i = 2 * z_i * tmp + J_I;
		iter++;
	}
	if (iter == MAX_ITER)
		put_pixel_to_image(x, y, data, COLORS[0]);
	else
		put_pixel_to_image(x, y, data, COLORS[1 + (iter % NB_COLORS)]);
}

void	julia_pos(int mode, t_data *data)
{
	if (mode == 1)
	{
		X_MIN = -1.5;
		X_MAX = 1.5;
		Y_MIN = -1.5;
		Y_MAX = 1.5;
		ZOOM = WIN_W / (X_MAX - X_MIN);
	}
	else
		ZOOM = WIN_W / (X_MAX - X_MIN);
}

void	julia(int mode, t_data *data)
{
	int		x;
	int		y;

	if (MUTATE == 1)
	{
		J_R = MOUSE_X / ZOOM + X_MIN;
		J_I = MOUSE_Y / ZOOM + Y_MIN;
	}
	if (mode < 3)
		julia_pos(mode, data);
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			draw_julia(x, y, data);
			x++;
		}
		y++;
	}
}
