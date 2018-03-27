/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:14:41 by axbal             #+#    #+#             */
/*   Updated: 2018/03/27 18:33:54 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define C 0xDDDDDD
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
# define J_R data->j_r
# define J_I data->j_i
# define MODEL data->model
# define MUTATE data->mutate
# define ZOOM data->zoom
# define COLORS data->colors
# define NB_COLORS data->nb_colors
# define SCHEME data->color_scheme
# define MOUSE_X data->mouse_x
# define MOUSE_Y data->mouse_y
# define MAX_ITER data->max_iter
# define D_ITER data->d_iter
# define OPTIONS data->options

typedef struct		s_fdot
{
	float			x;
	float			y;
}					t_fdot;

typedef struct		s_dot
{
	int				x;
	int				y;
}					t_dot;

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
	float			j_r;
	float			j_i;
	int				model;
	int				mutate;
	float			zoom;
	int				max_iter;
	int				d_iter;
	t_color			*colors;
	int				nb_colors;
	int				color_scheme;
	int				mouse_x;
	int				mouse_y;
	int				options;
}					t_data;

void				put_pixel_to_image(int x, int y, t_data *data, t_color c);
int					redirect_key(int key, t_data *data);
void				fractol(int mode, t_data *data);
int					refresh_expose(t_data *data);
void				move_img(int key, t_data *data);
int					track_mouse(int x, int y, t_data *data);
int					red_cross(int key);
t_color				*init_colors(t_data *data);
int					mouse_key_redirect(int button, int x, int y, t_data *data);
void				zoom_in(int x, int y, t_data *data);
void				zoom_out(int x, int y, t_data *data);
void				reset_pos(t_data *data);
void				usage(void);
int					get_options(char *str);
int					check_name(char *str);
void				mandelbrot(int mode, t_data *data);
void				julia(int mode, t_data *data);
void				burningship(int mode, t_data *data);
void				block_mutation(t_data *data);
float				absolute_val(float nb);
void				change_colors(t_data *data);
void				turn_options(t_data *data);
void				switch_fractal(t_data *data);
t_color				new_color(int r, int g, int b, int alpha);
t_color				*colorscheme1(t_data *data);
t_color				*colorscheme2(t_data *data);
t_color				*colorscheme3(t_data *data);
t_color				*colorscheme4(t_data *data);
t_color				*colorscheme5(t_data *data);

#endif
