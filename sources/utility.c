/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:15:47 by axbal             #+#    #+#             */
/*   Updated: 2018/03/26 16:25:16 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	show_options(t_data *data)
{
	mlx_string_put(MLX, WIN, 10, 1, C, "Press 'o' to show/hide options");
	mlx_string_put(MLX, WIN, 10, 16, C, "Press 'c' to change colors");
	mlx_string_put(MLX, WIN, 10, 31, C, "Press 'b' to block the julia set");
	mlx_string_put(MLX, WIN, 10, 46, C, "Press 'r' to reset your position");
	mlx_string_put(MLX, WIN, 10, 61, C, "Use the arrow keys to move the image");
	mlx_string_put(MLX, WIN, 10, 76, C, "Zoom in and out with the mouse wheel");
}

int		refresh_expose(t_data *data)
{
	mlx_clear_window(MLX, WIN);
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_X, IMG_Y);
	if (OPTIONS == 1)
		show_options(data);
	return (0);
}

void	usage(void)
{
	ft_putstr("usage : Fractol [\"mandelbrot\" ||  \"julia\"");
	ft_putstr(" || \"burningship\"] [option]\n");
}

void	reset_image(t_data *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIN_W, WIN_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	BPP /= 8;
}

int		get_options(char *str)
{
	int		nb;

	nb = 0;
	if (!str)
		return (0);
	if (ft_strncmp(str, "-size", 5) == 0)
		nb = ft_atoi(str + 5);
	else
	{
		ft_putstr("Invalid parameter.\n");
		return (0);
	}
	if (nb >= 100 && nb <= 2000)
		return (nb);
	ft_putstr("Size must be between 100 and 2000;\n");
	ft_putstr("starting with default parameters.\n");
	return (0);
}
