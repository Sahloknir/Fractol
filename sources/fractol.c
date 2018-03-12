/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:26:38 by axbal             #+#    #+#             */
/*   Updated: 2018/03/12 14:17:21 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandelbrot(float c_r, float c_i, t_data *data)
{
	int			max_iter;
	int			iter;
	float		tmp;
	float		z_r;
	float		z_i;
	int			x;
	int			y;

	x = c_r;
	y = c_i;
	c_r = x / ZOOM_X + X_MIN;
	c_i = y / ZOOM_Y + Y_MIN;
	iter = 0;
	z_r = 0;
	z_i = 0;
	max_iter = 100;
	while (iter < max_iter && z_r * z_r + z_i * z_i < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		iter++;
	}
	if (iter == max_iter)
		put_pixel_to_image(x, y, data, COLORS[0]);
	else
		put_pixel_to_image(x, y, data, COLORS[1 + (iter % NB_COLORS)]);
}

void	draw_julia(float x, float y, t_data *data)
{
	int			max_iter;
	int			iter;
	float		tmp;
	float		z_r;
	float		z_i;
	float		c_r;
	float		c_i;

	c_r = MOUSE_X / ZOOM_X + X_MIN;
	c_i = MOUSE_Y / ZOOM_Y + Y_MIN;
	z_r = x / ZOOM_X + X_MIN;
	z_i = y / ZOOM_Y + Y_MIN;
	iter = 0;
	max_iter = 100;
	while (iter < max_iter && z_r * z_r + z_i * z_i < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		iter++;
	}
	if (iter == max_iter)
		put_pixel_to_image(x, y, data, COLORS[0]);
	else
		put_pixel_to_image(x, y, data, COLORS[1 + (iter % NB_COLORS)]);
}

void	map_pos(int mode, t_data *data)
{
	if (mode == 1)
	{
		X_MIN = -2.1;
		X_MAX = 0.6;
		Y_MIN = -1.2;
		Y_MAX = 1.2;
		ZOOM_X = WIN_W / (X_MAX - X_MIN);
		ZOOM_Y = WIN_H / (Y_MAX - Y_MIN);
	}
	else
	{
		ZOOM_X = WIN_W / (X_MAX - X_MIN);
		ZOOM_Y = WIN_H / (Y_MAX - Y_MIN);
	}
}

void	fractol(int mode, t_data *data)
{
	int		x;
	int		y;

	if (mode < 3)
		map_pos(mode, data);
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
