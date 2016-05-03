/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 16:53:38 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/30 16:53:40 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include <math.h>

void	init_color(t_col *col)
{
	col->sky_col = 0x6FCEEA;
	col->floor_col = 0x716358;
	col->wall_col = 0xA342D4;
}

void	init_mlx(t_mlx *mlx)
{
	int x;
	int y;

	mlx->menu = 0;
	mlx->move = 1;
	mlx->dirx = -1;
	mlx->diry = 0;
	mlx->planex = 0;
	mlx->planey = 0.66;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "WOLF3D");
	mlx->img_start = mlx_xpm_file_to_image(mlx->ptr, "menu.xpm", &x, &y);
	mlx->img_hand = mlx_xpm_file_to_image(mlx->ptr, "hand.xpm", &x, &y);
	mlx->img_wand = mlx_xpm_file_to_image(mlx->ptr, "wand.xpm", &x, &y);
}

void	init_img(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_data = mlx_get_data_addr(mlx->img, &mlx->nb_pix,
	&mlx->size_line, &mlx->endian);
}

void	init_calc(t_mlx *mlx, int x)
{
	mlx->camerax = 2 * x / (double)WIDTH - 1;
	mlx->rayposx = mlx->posx;
	mlx->rayposy = mlx->posy;
	mlx->raydirx = mlx->dirx + mlx->planex * mlx->camerax;
	mlx->raydiry = mlx->diry + mlx->planey * mlx->camerax;
	mlx->mapx = (int)mlx->rayposx;
	mlx->mapy = (int)mlx->rayposy;
	mlx->deltadistx = sqrt(1 + (mlx->raydiry * mlx->raydiry) /
	(mlx->raydirx * mlx->raydirx));
	mlx->deltadisty = sqrt(1 + (mlx->raydirx * mlx->raydirx) /
	(mlx->raydiry * mlx->raydiry));
}
