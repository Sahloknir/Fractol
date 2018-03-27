/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:18:09 by axbal             #+#    #+#             */
/*   Updated: 2018/03/27 11:05:34 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandelbrot(t_dot d, t_data *data)
{
	int			iter;
	float		tmp;
	t_fdot		b;
	float		z_r;
	float		z_i;

	b.x = d.x / ZOOM + X_MIN;
	b.y = d.y / ZOOM + Y_MIN;
	iter = 0;
	z_r = 0;
	z_i = 0;
	while (iter < MAX_ITER && z_r * z_r + z_i * z_i < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + b.x;
		z_i = 2 * z_i * tmp + b.y;
		iter++;
	}
	if (iter == MAX_ITER)
		put_pixel_to_image(d.x, d.y, data, COLORS[0]);
	else
		put_pixel_to_image(d.x, d.y, data, COLORS[1 + (iter % NB_COLORS)]);
}

void	mand_pos(int mode, t_data *data)
{
	if (mode == 1)
	{
		X_MIN = -2.1;
		X_MAX = 0.6;
		Y_MIN = -1.35;
		Y_MAX = 1.35;
		ZOOM = WIN_W / (X_MAX - X_MIN);
	}
	else
		ZOOM = WIN_W / (X_MAX - X_MIN);
}

void	mandelbrot(int mode, t_data *data)
{
	t_dot	d;

	if (mode < 3)
		mand_pos(mode, data);
	d.y = 0;
	while (d.y < WIN_H)
	{
		d.x = 0;
		while (d.x < WIN_W)
		{
			draw_mandelbrot(d, data);
			d.x++;
		}
		d.y++;
	}
}
