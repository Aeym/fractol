/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:05:18 by ealrick           #+#    #+#             */
/*   Updated: 2017/10/24 16:05:23 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_gda g;

	g.usg = usage(av[1]);
	init_struc(&g);
	if (ac != 2 || g.usg == 0)
		return (0);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, WIDTH, HEIGHT,
		ft_strjoin("Fractol : ", av[1]));
	init_win(&g);
	mlx_hook(g.win, KEYPRESS, KEYPRESSMASK, hook_key, &g);
	mlx_mouse_hook(g.win, mouse_hook, &g);
	mlx_hook(g.win, MOTIONNOTIFY, POINTERMOTIONMASK, motion_hook, &g);
	mlx_loop_hook(g.mlx, loop_hook, &g);
	mlx_hook(g.win, 17, 1L << 0, hook_close, g.mlx);
	mlx_loop(g.mlx);
}
