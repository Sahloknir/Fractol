/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:50:35 by axbal             #+#    #+#             */
/*   Updated: 2018/04/21 17:05:41 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		move_img(int key, t_data *data)
{
	float	tmp;

	tmp = (X_MAX - X_MIN) / 100;
	if (key == 123 || key == 124)
	{
		X_MIN += key == 123 ? -tmp : tmp;
		X_MAX += key == 123 ? -tmp : tmp;
	}
	else if (key == 126)
	{
		Y_MIN -= tmp;
		Y_MAX -= tmp;
	}
	else if (key == 125)
	{
		Y_MIN += tmp;
		Y_MAX += tmp;
	}
	fractol(2, data);
	refresh_expose(data);
	return (0);
}

int		track_mouse(int x, int y, t_data *data)
{
	if (MODEL == 2 && MUTATE == 1)
	{
		MOUSE_X = x;
		MOUSE_Y = y;
		julia(3, data);
		refresh_expose(data);
	}
	return (0);
}

void	reset_pos(t_data *data)
{
	MAX_ITER = 50;
	D_ITER = 50;
	fractol(1, data);
	refresh_expose(data);
}

void	block_mutation(t_data *data)
{
	MUTATE *= -1;
}

void	turn_options(t_data *data)
{
	OPTIONS *= -1;
	refresh_expose(data);
}
