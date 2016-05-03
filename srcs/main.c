/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 17:07:51 by etermeau          #+#    #+#             */
/*   Updated: 2015/05/25 17:21:49 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

static int	key_hook(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	(void)keycode;
	mlx->move = 1;
	if (mlx->key == 53)
		exit (0);
	draw_all(mlx, 0);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}

static int	loop_hook(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (mlx->menu == 0)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_start, 345, 300);
		if (mlx->key == 36)
			mlx->menu = 1;
	}
	if (mlx->move == 1)
	{
		draw_all(mlx, 0);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_hand, 690, 600);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_wand, 740, 490);
	}
	mlx->move = 0;
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2)
	{
		load_map(&mlx, av[1]);
		init_mlx(&mlx);
		init_img(&mlx);
		mlx_key_hook(mlx.win, key_hook, &mlx);
		mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, check_key_press, &mlx);
		mlx_loop_hook(mlx.ptr, &loop_hook, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
	{
		ft_print_color(RED, "Wolf3D: Too many/few arguments.\n", 2);
		ft_print_color(RED, "Usage: ./Wolf3D [map]\n", 2);
	}
	return (0);
}
