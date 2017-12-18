/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:05:37 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/24 16:05:39 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	sq(float x)
{
	return (x * x);
}

void	set_ctoff(t_gda *g, int x, int y)
{
	g->offset_x += (double)(-1 * ((double)((g->center_x - x) /
		(g->zoom_x)) / WIDTH) * (g->x2 - g->x1));
	g->offset_y += (double)(((double)((g->center_y - y) /
		(g->zoom_y)) / HEIGHT) * (g->y2 - g->y1));
	g->center_x = x;
	g->center_y = y;
}

void	trace_pixel(t_gda g, t_coo c, int i)
{
	if (c.x < WIDTH && c.x > 0 && c.y < HEIGHT && c.y > 0 && i < g.i_max)
	{
		g.gda[c.y * g.size_line + c.x * g.bpp / 8] = g.color + i;
		g.gda[c.y * g.size_line + c.x * g.bpp / 8 + 1] = (2 + g.color) * i;
		g.gda[c.y * g.size_line + c.x * g.bpp / 8 + 2] = (5 + g.color) * i;
	}
}

int		usage(char *av)
{
	if (av)
	{
		if (ft_strcmp(av, "Mandelbrot") == 0 || ft_strcmp(av, "1") == 0)
			return (1);
		else if (ft_strcmp(av, "Julia") == 0 || ft_strcmp(av, "2") == 0)
			return (2);
		else if (ft_strcmp(av, "DoubleMandel") == 0 || ft_strcmp(av, "3") == 0)
			return (3);
	}
	ft_putstr("usage : ./fractol [Fractal name]\n\t\t- Mandelbrot (1)\n\t\t");
	ft_putstr("- Julia (2)\n\t\t- DoubleMandel (3)\n");
	return (0);
}
