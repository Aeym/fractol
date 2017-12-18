/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:05:48 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/24 16:05:50 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6
# define WIDTH 896
# define HEIGHT 800

typedef struct	s_gda
{
	char		*av1;
	char		*gda;
	int			bpp;
	int			size_line;
	int			usg;
	int			end;
	int			i;
	float		tmp;
	void		*mlx;
	void		*win;
	void		*img;
	int			x;
	int			y;
	float		i_max;
	float		zoom;
	float		offset_x;
	float		offset_y;
	float		center_x;
	float		center_y;
	float		mouse_x;
	float		mouse_y;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		d_zoom_x;
	float		d_zoom_y;
	float		zoom_x;
	float		zoom_y;
	int			keycode;
	int			color;
}				t_gda;

typedef struct	s_mes
{
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		zoom_x;
	float		zoom_y;
	int			img_x;
	int			img_y;
}				t_mes;

typedef struct	s_coo
{
	int			x;
	int			y;
}				t_coo;

typedef struct	s_comp
{
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
}				t_comp;

void			init_struc(t_gda *g);
void			init_limit(t_gda *g);
void			init_img(t_gda *g);
void			init_win(t_gda *g);
void			trace_pixel(t_gda g, t_coo c, int i);
int				hook_close(void);
int				loop_hook(t_gda *g);
int				hook_key(int key, t_gda *g);
void			hook_key3(int key, t_gda *g);
void			hook_key2(int key, t_gda *g);
int				motion_hook(int x, int y, t_gda *g);
int				mouse_hook(int button, int x, int y, t_gda *g);
float			sq(float x);
void			mandel(t_gda g);
void			julia(t_gda g);
void			double_mandel(t_gda g);
int				usage(char *av);
void			set_ctoff(t_gda *g, int x, int y);

#endif
