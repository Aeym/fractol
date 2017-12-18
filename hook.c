/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:06:05 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/24 16:06:07 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_close(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	hook_key3(int key, t_gda *g)
{
	if (key == 12)
		g->i_max /= 1.5;
	if (key == 13)
		g->i_max *= 1.5;
	if (key == 1)
		g->color++;
	if (key == 0)
		g->color--;
	if (key == 53)
		exit(EXIT_SUCCESS);
}

void	hook_key2(int key, t_gda *g)
{
	if (key == 18)
	{
		g->usg = 1;
		init_struc(g);
	}
	if (key == 19)
	{
		g->usg = 2;
		init_struc(g);
	}
	if (key == 20)
	{
		g->usg = 3;
		init_struc(g);
	}
}

int		hook_key(int key, t_gda *g)
{
	g->keycode = key;
	hook_key2(key, g);
	hook_key3(key, g);
	if (key == 15)
		init_struc(g);
	if (key == 123)
		g->offset_x -= ((double)(-1 * ((10.0 / WIDTH) * (g->x2 - g->x1))))
		/ g->zoom_x / 0.5;
	if (key == 124)
		g->offset_x += ((double)(-1 * ((10.0 / WIDTH) * (g->x2 - g->x1))))
		/ g->zoom_x / 0.5;
	if (key == 125)
		g->offset_y += (double)((10.0 / HEIGHT) * (g->y2 - g->y1))
		/ g->zoom_y / 0.5;
	if (key == 126)
		g->offset_y -= (double)((10.0 / HEIGHT) * (g->y2 - g->y1))
		/ g->zoom_y / 0.5;
	mlx_destroy_image(g->mlx, g->img);
	init_win(g);
	return (0);
}
