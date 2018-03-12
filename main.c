/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:33:50 by axbal             #+#    #+#             */
/*   Updated: 2018/03/11 19:26:54 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		refresh_expose(t_data *data)
{
	mlx_clear_window(MLX, WIN);
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_X, IMG_Y);
	mlx_string_put(MLX, WIN, 5, 1, 0xDDDDDD, "X = ");
	mlx_string_put(MLX, WIN, 5, 21, 0xDDDDDD, "Y = ");
	mlx_string_put(MLX, WIN, 45, 1, 0xDDDDDD, ft_itoa(MOUSE_X));
	mlx_string_put(MLX, WIN, 45, 21, 0xDDDDDD, ft_itoa(MOUSE_Y));
	return (0);
}

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
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_W, WIN_H, "Mandelbrot");
	IMG = mlx_new_image(MLX, WIN_W, WIN_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	COLORS = init_colors(data);
	BPP /= 8;
	return (data);
}

int		test_func(int x, int y, t_data *data)
{
	MOUSE_X = x;
	MOUSE_Y = y;
	refresh_expose(data);
	return (0);
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
//	mlx_mouse_hook(WIN, test_func, data);
	mlx_hook(WIN, 6, 1L<<6, test_func, data);
	mlx_expose_hook(WIN, refresh_expose, data);
	mlx_loop(MLX);
	return (0);
}
