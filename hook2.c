/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:06:13 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/24 16:06:14 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		motion_hook(int x, int y, t_gda *g)
{
	if (g->usg == 2)
	{
		g->mouse_x = x;
		g->mouse_y = y;
		mlx_destroy_image(g->mlx, g->img);
		init_win(g);
	}
	return (0);
}

void	de_zoom(t_gda *g, int z, double j)
{
	set_ctoff(g, g->x, g->y);
	g->zoom_x = (z == 1) ? g->zoom_x * j : g->zoom_x / j;
	g->zoom_y = (z == 1) ? g->zoom_y * j : g->zoom_y / j;
	g->i_max = (z == 1) ? g->i_max * 1.1 : g->i_max / 1.1;
	mlx_destroy_image(g->mlx, g->img);
	init_win(g);
	set_ctoff(g, WIDTH / 2, HEIGHT / 2);
}

int		loop_hook(t_gda *g)
{
	(g->keycode == 69) ? de_zoom(g, 1, 1.1) : 0;
	(g->keycode == 78) ? de_zoom(g, -1, 1.1) : 0;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_gda *g)
{
	g->x = x;
	g->y = y;
	if (button == 4)
		de_zoom(g, 1, 1.1);
	else if (button == 5)
		de_zoom(g, -1, 1.1);
	return (0);
}
