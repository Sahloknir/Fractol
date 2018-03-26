/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:26:31 by axbal             #+#    #+#             */
/*   Updated: 2018/03/26 16:26:43 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_colors(t_data *data)
{
	if (SCHEME == 5)
		SCHEME = 1;
	else
		SCHEME += 1;
	free(COLORS);
	COLORS = init_colors(data);
	fractol(3, data);
	refresh_expose(data);
}

int		mouse_key_redirect(int button, int x, int y, t_data *data)
{
	if (button == 4)
		zoom_in(x, y, data);
	if (button == 5)
		zoom_out(x, y, data);
	return (0);
}

int		red_cross(int key)
{
	exit(0);
	return (key);
}
