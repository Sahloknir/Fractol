/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:26:38 by axbal             #+#    #+#             */
/*   Updated: 2018/03/22 13:39:06 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol(int mode, t_data *data)
{
	if (MODEL == 1)
		mandelbrot(mode, data);
	else if (MODEL == 2)
		julia(mode, data);
	else if (MODEL == 3)
		burningship(mode, data);
}
