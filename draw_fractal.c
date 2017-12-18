/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:05:30 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/24 16:05:32 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandel(t_gda g)
{
	t_comp	p;
	t_coo	c;

	c.x = 0;
	while (c.x < WIDTH)
	{
		c.y = 0;
		while (c.y < HEIGHT)
		{
			p.c_r = (c.x - g.center_x) / g.d_zoom_x + g.x1 + g.offset_x;
			p.c_i = (g.center_y - c.y) / g.d_zoom_y + g.y1 + g.offset_y;
			p.z_r = 0;
			p.z_i = 0;
			g.i = -1;
			while (++g.i < g.i_max && (p.z_r * p.z_r + p.z_i * p.z_i) < 4.0)
			{
				g.tmp = p.z_r;
				p.z_r = p.z_r * p.z_r - p.z_i * p.z_i + p.c_r;
				p.z_i = 2.0 * p.z_i * g.tmp + p.c_i;
			}
			trace_pixel(g, c, g.i);
			c.y++;
		}
		c.x++;
	}
}

void		julia(t_gda g)
{
	t_comp	p;
	t_coo	c;

	c.x = 0;
	while (c.x < WIDTH)
	{
		c.y = 0;
		while (c.y < HEIGHT)
		{
			p.c_r = g.mouse_x / 1000 - 1;
			p.c_i = g.mouse_y / 400 - 1;
			p.z_r = (c.x - g.center_x) / g.d_zoom_x + g.x1 + g.offset_x;
			p.z_i = (g.center_y - c.y) / g.d_zoom_y + g.y1 + g.offset_y;
			g.i = -1;
			while (++g.i < g.i_max && (p.z_r * p.z_r + p.z_i * p.z_i) < 4.0)
			{
				g.tmp = p.z_r;
				p.z_r = p.z_r * p.z_r - p.z_i * p.z_i + p.c_r;
				p.z_i = 2.0 * p.z_i * g.tmp + p.c_i;
			}
			trace_pixel(g, c, g.i);
			c.y++;
		}
		c.x++;
	}
}

void		double_mandel(t_gda g)
{
	t_comp	p;
	t_coo	c;

	c.x = 0;
	while (c.x < WIDTH)
	{
		c.y = 0;
		while (c.y < HEIGHT)
		{
			p.c_r = (c.x - g.center_x) / g.d_zoom_x + g.x1 + g.offset_x;
			p.c_i = (g.center_y - c.y) / g.d_zoom_y + g.y1 + g.offset_y;
			p.z_r = 0;
			p.z_i = 0;
			g.i = -1;
			while (++g.i < g.i_max && (p.z_r * p.z_r + p.z_i * p.z_i) < 4.0)
			{
				g.tmp = p.z_r;
				p.z_r = sq(p.z_r) * p.z_r - 3 * sq(p.z_i) * p.z_r + p.c_r;
				p.z_i = 3.0 * p.z_i * sq(g.tmp) - sq(p.z_i) * p.z_i + p.c_i;
			}
			trace_pixel(g, c, g.i);
			c.y++;
		}
		c.x++;
	}
}
