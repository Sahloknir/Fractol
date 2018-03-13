/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:33:50 by axbal             #+#    #+#             */
/*   Updated: 2018/03/13 16:42:09 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_data		*global_init(void)
{
	t_data		*data;

	if (!(data = (t_data *)malloc(sizeof(t_data) * 1)))
		return (NULL);
	WIN_W = 700;
	WIN_H = 700;
	IMG_X = 0;
	IMG_Y = 0;
	MOUSE_X = 0;
	MOUSE_Y = 0;
	ZOOM = 0.5;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_W, WIN_H, "Mandelbrot");
	IMG = mlx_new_image(MLX, WIN_W, WIN_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	COLORS = init_colors(data);
	BPP /= 8;
	return (data);
}

int			main(int argc, char **argv)
{
	t_data		*data;

	argc = 0;
	argv = NULL;
	data = global_init();
	fractol(1, data);
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_X, IMG_Y);
	mlx_key_hook(WIN, redirect_key, data);
	mlx_mouse_hook(WIN, zoom_in, data);
	mlx_hook(WIN, 6, 1L<<6, track_mouse, data);
	mlx_hook(WIN, 17, 1L<<17, red_cross, NULL);
	mlx_expose_hook(WIN, refresh_expose, data);
	refresh_expose(data);
	mlx_loop(MLX);
	return (0);
}
