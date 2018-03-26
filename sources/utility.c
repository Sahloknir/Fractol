/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:15:47 by axbal             #+#    #+#             */
/*   Updated: 2018/03/26 15:54:55 by axbal            ###   ########.fr       */
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

int		check_name(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(str, "julia") == 0)
		return (2);
	else if (ft_strcmp(str, "burningship") == 0)
		return (3);
	return (0);
}

int		redirect_key(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	else if (key == 15)
		reset_pos(data);
	else if (key == 11)
		block_mutation(data);
	else if (key >= 123 && key <= 126)
		move_img(key, data);
	else if (key == 8)
		change_colors(data);
	else if (key == 31)
		turn_options(data);
	return (key);
}

float	absolute_val(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
