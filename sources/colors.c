/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:53:33 by axbal             #+#    #+#             */
/*   Updated: 2018/03/22 17:00:55 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color		new_color(int r, int g, int b, int alpha)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.alpha = alpha;
	return (color);
}

t_color		*init_colors(t_data *data)
{
	if (SCHEME == 1)
		return (colorscheme1(data));
	else if (SCHEME == 2)
		return (colorscheme2(data));
	else if (SCHEME == 3)
		return (colorscheme3(data));
	else if (SCHEME == 4)
		return (colorscheme4(data));
	return (colorscheme5(data));
}
