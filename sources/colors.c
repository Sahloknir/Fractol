/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:53:33 by axbal             #+#    #+#             */
/*   Updated: 2018/03/11 12:25:52 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color		*init_colors(t_data *data)
{
	t_color		*colors;

	if (!(colors = (t_color *)malloc(sizeof(t_color) * 8)))
		return (NULL);
	data->nb_colors = 7;
	colors[0].r = 0;
	colors[0].g = 0;
	colors[0].b = 0;
	colors[0].alpha = 0;
	colors[1].r = 56;
	colors[1].g = 96;
	colors[1].b = 137;
	colors[1].alpha = 0;
	colors[2].r = 114;
	colors[2].g = 123;
	colors[2].b = 158;
	colors[2].alpha = 0;
	colors[3].r = 61;
	colors[3].g = 88;
	colors[3].b = 116;
	colors[3].alpha = 0;
	colors[4].r = 49;
	colors[4].g = 59;
	colors[4].b = 87;
	colors[4].alpha = 0;
	colors[5].r = 48;
	colors[5].g = 63;
	colors[5].b = 92;
	colors[5].alpha = 0;
	colors[6].r = 46;
	colors[6].g = 67;
	colors[6].b = 98;
	colors[6].alpha = 0;
	colors[7].r = 28;
	colors[7].g = 39;
	colors[7].b = 68;
	colors[7].alpha = 0;

	return (colors);
}
