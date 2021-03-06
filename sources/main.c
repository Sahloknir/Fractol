/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:33:50 by axbal             #+#    #+#             */
/*   Updated: 2018/04/21 17:23:00 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		init_var(t_data *data, int size)
{
	WIN_W = 700;
	WIN_H = 700;
	if (size != 0)
	{
		WIN_W = size;
		WIN_H = size;
	}
	IMG_X = 0;
	IMG_Y = 0;
	MOUSE_X = 0;
	MOUSE_Y = 0;
	MAX_ITER = 50;
	D_ITER = 50;
	MUTATE = 1;
	OPTIONS = 1;
	SCHEME = 1;
}

t_data		*global_init(int size)
{
	t_data		*data;

	if (!(data = (t_data *)malloc(sizeof(t_data) * 1)))
		return (NULL);
	init_var(data, size);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_W, WIN_H, "fractol");
	IMG = mlx_new_image(MLX, WIN_W, WIN_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	COLORS = init_colors(data);
	BPP /= 8;
	return (data);
}

void		mainloop(int size, int fractal)
{
	t_data	*data;

	data = global_init(size);
	MODEL = fractal;
	fractol(1, data);
	mlx_key_hook(WIN, redirect_key, data);
	mlx_mouse_hook(WIN, mouse_key_redirect, data);
	mlx_hook(WIN, 6, 1L << 6, track_mouse, data);
	mlx_hook(WIN, 17, 1L << 17, red_cross, NULL);
	mlx_hook(WIN, 2, 1L << 0, move_img, data);
	mlx_expose_hook(WIN, refresh_expose, data);
	refresh_expose(data);
	mlx_loop(MLX);
}

int			main(int argc, char **argv)
{
	int		size;
	int		fractal;

	size = 0;
	if (argc < 2 || argc > 3)
	{
		usage();
		return (0);
	}
	if ((fractal = check_name(argv[1])) != 0)
		mainloop(get_options(argv[2]), fractal);
	else
		usage();
	return (0);
}
