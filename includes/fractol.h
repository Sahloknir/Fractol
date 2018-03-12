/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:14:41 by axbal             #+#    #+#             */
/*   Updated: 2018/03/12 14:24:27 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include <stdio.h>

# define ABS(value) value < 0 ? -value : value
# define MLX data->mlx_ptr
# define WIN data->win_ptr
# define WIN_W data->win_w
# define WIN_H data->win_h
# define IMG data->img_ptr
# define IMG_STR data->img_str
# define IMG_X data->img_x
# define IMG_Y data->img_y
# define BPP data->bpp
# define S_L data->s_l
# define ENDIAN data->endian
# define X_MIN data->x_min
# define X_MAX data->x_max
# define Y_MIN data->y_min
# define Y_MAX data->y_max
# define ZOOM_X data->zoom_x
# define ZOOM_Y data->zoom_y
# define COLORS data->colors
# define NB_COLORS data->nb_colors
# define MOUSE_X data->mouse_x
# define MOUSE_Y data->mouse_y

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				alpha;
}					t_color;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_str;
	int				bpp;
	int				s_l;
	int				endian;
	int				img_x;
	int				img_y;
	int				win_h;
	int				win_w;
	float			x_min;
	float			x_max;
	float			y_min;
	float			y_max;
	int				x_o;
	int				y_o;
	float			zoom_x;
	float			zoom_y;
	t_color			*colors;
	int				nb_colors;
	int				mouse_x;
	int				mouse_y;
}					t_data;

void		put_pixel_to_image(int x, int y, t_data *data, t_color color);
int			redirect_key(int key, t_data *data);
void		fractol(int mode, t_data *data);
int			refresh_expose(t_data * data);
void		move_img(int key, t_data *data);
t_color		*init_colors(t_data *data);

//char		*ft_ftoa(float nb);

#endif
