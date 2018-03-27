/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:31:56 by axbal             #+#    #+#             */
/*   Updated: 2018/03/27 17:52:07 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_in(int x, int y, t_data *data)
{
	X_MIN = ((x / ZOOM + X_MIN) - ((ZOOM * 1.1) / 2)) + ((ZOOM * 1.1) / 2)
	- (x / (ZOOM * 1.1));
	Y_MIN = ((y / ZOOM + Y_MIN) - ((ZOOM * 1.1) / 2)) + ((ZOOM * 1.1) / 2)
	- (y / (ZOOM * 1.1));
	ZOOM *= 1.1;
	X_MAX = X_MIN + (WIN_W / ZOOM);
	Y_MAX = Y_MIN + (WIN_H / ZOOM);
	if (D_ITER >= 50 && D_ITER < 300)
		MAX_ITER += 2;
	D_ITER += 2;
	fractol(3, data);
	refresh_expose(data);
}

void	zoom_out(int x, int y, t_data *data)
{
	X_MIN = ((x / ZOOM + X_MIN) - ((ZOOM / 1.1) / 2)) + ((ZOOM / 1.1) / 2)
	- (x / (ZOOM / 1.1));
	Y_MIN = ((y / ZOOM + Y_MIN) - ((ZOOM / 1.1) / 2)) + ((ZOOM / 1.1) / 2)
	- (y / (ZOOM / 1.1));
	ZOOM /= 1.1;
	X_MAX = X_MIN + (WIN_W / ZOOM);
	Y_MAX = Y_MIN + (WIN_H / ZOOM);
	if (D_ITER > 50 && D_ITER <= 300)
		MAX_ITER -= 2;
	D_ITER -= 2;
	fractol(3, data);
	refresh_expose(data);
}
