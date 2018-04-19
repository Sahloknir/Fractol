/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:24:55 by axbal             #+#    #+#             */
/*   Updated: 2018/04/19 17:23:11 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	else if (key == 8)
		change_colors(data);
	else if (key == 31)
		turn_options(data);
	else if (key == 1)
		switch_fractal(data);
	return (key);
}

float	absolute_val(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
