/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:31:21 by axbal             #+#    #+#             */
/*   Updated: 2018/03/11 20:53:01 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ftoa_malloc_size(int nb)
{
	int		i;

	i = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

int		find_dot(float nb, int *round)
{
	int		dot;

	return (dot);
}

char	*ft_ftoa(float nb)
{
	int		round;
	int		mult;
	int		c;
	int		i;
	char	*str;
	int		len;

	round = (int)nb;
	mult = 1;
	c = find_dot(nb, &round);
	len = ftoa_malloc_size(round);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (nb >= 10)
	{
		nb = nb / 10;
		mult *= 10;
	}
	str[len] = '\0';
	i = -1;
	while (++i < len)
	{
		str[i] = (c != 0 ? (round / mult) % 10 + '0' : '.');
		mult = (c == 0 ? mult : mult / 10);
		c--;
	}
	return (str);
}
