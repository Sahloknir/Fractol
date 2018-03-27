/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:00:24 by axbal             #+#    #+#             */
/*   Updated: 2018/03/27 11:06:31 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color		*colorscheme1(t_data *data)
{
	t_color		*colors;

	NB_COLORS = 16;
	if (!(colors = (t_color *)malloc(sizeof(t_color) * (NB_COLORS + 1))))
		return (NULL);
	colors[0] = new_color(0, 0, 0, 0);
	colors[1] = new_color(66, 30, 15, 0);
	colors[2] = new_color(25, 7, 26, 0);
	colors[3] = new_color(9, 1, 47, 0);
	colors[4] = new_color(4, 4, 73, 0);
	colors[5] = new_color(0, 7, 100, 0);
	colors[6] = new_color(12, 44, 138, 0);
	colors[7] = new_color(24, 82, 177, 0);
	colors[8] = new_color(57, 125, 209, 0);
	colors[9] = new_color(134, 181, 229, 0);
	colors[10] = new_color(211, 236, 248, 0);
	colors[11] = new_color(241, 233, 191, 0);
	colors[12] = new_color(248, 201, 95, 0);
	colors[13] = new_color(255, 170, 0, 0);
	colors[14] = new_color(204, 128, 0, 0);
	colors[15] = new_color(153, 87, 0, 0);
	colors[16] = new_color(106, 52, 3, 0);
	return (colors);
}

t_color		*colorscheme2(t_data *data)
{
	t_color		*colors;

	NB_COLORS = 5;
	if (!(colors = (t_color *)malloc(sizeof(t_color) * (NB_COLORS + 1))))
		return (NULL);
	colors[0] = new_color(0, 0, 0, 0);
	colors[1] = new_color(75, 56, 50, 0);
	colors[2] = new_color(133, 68, 66, 0);
	colors[3] = new_color(255, 244, 230, 0);
	colors[4] = new_color(60, 47, 47, 0);
	colors[5] = new_color(190, 155, 123, 0);
	return (colors);
}

t_color		*colorscheme3(t_data *data)
{
	t_color		*colors;

	NB_COLORS = 5;
	if (!(colors = (t_color *)malloc(sizeof(t_color) * (NB_COLORS + 1))))
		return (NULL);
	colors[0] = new_color(0, 0, 0, 0);
	colors[1] = new_color(79, 51, 27, 0);
	colors[2] = new_color(210, 109, 26, 0);
	colors[3] = new_color(242, 202, 78, 0);
	colors[4] = new_color(255, 250, 202, 0);
	colors[5] = new_color(255, 180, 69, 0);
	return (colors);
}

t_color		*colorscheme4(t_data *data)
{
	t_color		*colors;

	NB_COLORS = 5;
	if (!(colors = (t_color *)malloc(sizeof(t_color) * (NB_COLORS + 1))))
		return (NULL);
	colors[0] = new_color(0, 0, 0, 0);
	colors[1] = new_color(88, 34, 30, 0);
	colors[2] = new_color(141, 83, 48, 0);
	colors[3] = new_color(201, 150, 103, 0);
	colors[4] = new_color(96, 109, 91, 0);
	colors[5] = new_color(51, 57, 49, 0);
	return (colors);
}

t_color		*colorscheme5(t_data *data)
{
	t_color		*colors;

	NB_COLORS = 4;
	if (!(colors = (t_color *)malloc(sizeof(t_color) * (NB_COLORS + 1))))
		return (NULL);
	colors[0] = new_color(0, 0, 0, 0);
	colors[1] = new_color(53, 37, 21, 0);
	colors[2] = new_color(81, 58, 40, 0);
	colors[3] = new_color(156, 127, 95, 0);
	colors[4] = new_color(210, 188, 151, 0);
	return (colors);
}
