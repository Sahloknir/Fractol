/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:15:47 by axbal             #+#    #+#             */
/*   Updated: 2018/03/11 13:44:26 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_img(int key, t_data *data)
{
	if (key == 124)
	{
		X_MIN -= 0.1;
		X_MAX -= 0.1;
	}
	else if (key == 123)
	{
		X_MIN += 0.1;
		X_MAX += 0.1;
	}
	else if (key == 126)
		IMG_Y += 10;
	else if (key == 125)
		IMG_Y -= 10;
	fractol(2, data);
	refresh_expose(data);
}

int		redirect_key(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	else if (key == 8)
	{
		ZOOM_X *= 2;
		ZOOM_Y *= 2;
		X_MIN /= 2;
		X_MAX /= 2;
		Y_MIN /= 2;
		Y_MAX /= 2;
		printf("%lf", ZOOM_X);
		mlx_destroy_image(MLX, IMG);
		IMG = mlx_new_image(MLX, WIN_W, WIN_H);
		IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
		BPP /= 8;
		fractol(2, data);
		refresh_expose(data);
	}
	else if (key >= 123 && key <= 126)
		move_img(key, data);
	else
		ft_putnbr(key);
	return (key);
}
