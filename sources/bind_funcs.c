/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:50:35 by axbal             #+#    #+#             */
/*   Updated: 2018/03/13 16:41:52 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_img(int key, t_data *data)
{
	if (key == 123)
	{
		X_MIN -= 0.1;
		X_MAX -= 0.1;
	}
	else if (key == 124)
	{
		X_MIN += 0.1;
		X_MAX += 0.1;
	}
	else if (key == 126)
	{
		Y_MIN -= 0.1;
		Y_MAX -= 0.1;
	}
	else if (key == 125)
	{
		Y_MIN += 0.1;
		Y_MAX += 0.1;
	}
	fractol(2, data);
	refresh_expose(data);
}

int		track_mouse(int x, int y, t_data *data)
{
//	if (ABS(MOUSE_X - x) >= 10 || ABS(MOUSE_Y - y) >= 10 || MOUSE_X == 0
//			|| MOUSE_Y == 0)
//	{
		MOUSE_X = x;
		MOUSE_Y = y;
		fractol(3, data);
		refresh_expose(data);
//	}
	return (0);
}

int		zoom_in(int button, int x, int y, t_data *data)
{
	float	x2;
	float	y2;

	x2 = x / ZOOM_X + X_MIN;
	y2 = y / ZOOM_Y + Y_MIN;
	button = 0;
	ZOOM /= 1.1;
	ZOOM_X /= 1.1;
	ZOOM_Y /= 1.1;
	X_MIN = x2 - ZOOM;
	X_MAX = x2 + ZOOM;
	Y_MIN = y2 - ZOOM;
	Y_MAX = y2 + ZOOM;

	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIN_W, WIN_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	BPP /= 8;
	fractol(2, data);
	refresh_expose(data);
	return (0);
}

int		red_cross(int key)
{
	exit(0);
	return (key);
}
