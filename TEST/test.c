/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 20:09:53 by axbal             #+#    #+#             */
/*   Updated: 2018/03/12 14:09:41 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"
#include <stdio.h>

char	*ft_ftoa(float nb);

int		main(void)
{
	char	*str;

	str = ft_ftoa(123.122);
	printf("%s\n", str);
	return (0);
}