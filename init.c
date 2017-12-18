/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:05:56 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/24 16:05:58 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_limit(t_gda *g)
{
	if (g->usg == 1)
	{
		g->x1 = -2.1;
		g->x2 = 0.6;
		g->y1 = -1.2;
		g->y2 = 1.2;
	}
	else if (g->usg == 2)
	{
		g->x1 = -1;
		g->x2 = 1;
		g->y1 = -1.2;
		g->y2 = 1.2;
	}
	else if (g->usg == 3)
	{
		g->x1 = -1.3;
		g->x2 = 1.3;
		g->y1 = -1.4;
		g->y2 = 1.4;
	}
}

void	init_struc(t_gda *g)
{
	init_limit(g);
	g->i_max = 30;
	g->center_x = WIDTH / 2;
	g->center_y = HEIGHT / 2;
	g->offset_x = (double)(-1 * ((double)(-WIDTH / 2) / WIDTH)
		* (g->x2 - g->x1));
	g->offset_y = (double)((double)(HEIGHT / 2) / HEIGHT) * (g->y2 - g->y1);
	g->mouse_x = WIDTH / 2;
	g->mouse_y = HEIGHT / 2;
	g->zoom_x = 1;
	g->zoom_y = 1;
	g->color = 0;
}

void	init_win(t_gda *g)
{
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->gda = mlx_get_data_addr(g->img, &g->bpp, &g->size_line, &g->end);
	g->d_zoom_x = g->zoom_x * WIDTH / (g->x2 - g->x1);
	g->d_zoom_y = g->zoom_y * HEIGHT / (g->y2 - g->y1);
	if (g->usg == 1)
		mandel(*g);
	else if (g->usg == 2)
		julia(*g);
	else if (g->usg == 3)
		double_mandel(*g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}
