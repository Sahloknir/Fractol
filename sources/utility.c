/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:15:47 by axbal             #+#    #+#             */
/*   Updated: 2018/03/13 12:40:37 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		refresh_expose(t_data *data)
{
	float	x;
	float	y;

	mlx_clear_window(MLX, WIN);
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_X, IMG_Y);
	mlx_string_put(MLX, WIN, 5, 1, 0xDDDDDD, "X = ");
	mlx_string_put(MLX, WIN, 5, 21, 0xDDDDDD, "Y = ");
	mlx_string_put(MLX, WIN, 45, 1, 0xDDDDDD, ft_itoa(MOUSE_X));
	mlx_string_put(MLX, WIN, 45, 21, 0xDDDDDD, ft_itoa(MOUSE_Y));

	x = MOUSE_X / ZOOM_X + X_MIN;
	y = MOUSE_Y / ZOOM_Y + Y_MIN;
	printf("X = %lf ; Y = %lf\n", x, y);

	return (0);
}

int		redirect_key(int key, t_data *data)
{
	if (key == 53)
		exit(0);
//	else if (key == 8)
//		zoom_in(data);
	else if (key >= 123 && key <= 126)
		move_img(key, data);
	else
		ft_putnbr(key);
	return (key);
}
