/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 16:51:43 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/30 16:51:45 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	direction_wall(t_mlx *mlx)
{
	if (mlx->raydirx < 0)
	{
		mlx->stepx = -1;
		mlx->sidedistx = (mlx->rayposx - mlx->mapx) * mlx->deltadistx;
	}
	else
	{
		mlx->stepx = 1;
		mlx->sidedistx = (mlx->mapx + 1.0 - mlx->rayposx) * mlx->deltadistx;
	}
	if (mlx->raydiry < 0)
	{
		mlx->stepy = -1;
		mlx->sidedisty = (mlx->rayposy - mlx->mapy) * mlx->deltadisty;
	}
	else
	{
		mlx->stepy = 1;
		mlx->sidedisty = (mlx->mapy + 1.0 - mlx->rayposy) * mlx->deltadisty;
	}
}

void	check_mouvement(t_mlx *mlx)
{
	if (mlx->sidedistx < mlx->sidedisty)
	{
		mlx->sidedistx += mlx->deltadistx;
		mlx->mapx += mlx->stepx;
		mlx->side = 0;
	}
	else
	{
		mlx->sidedisty += mlx->deltadisty;
		mlx->mapy += mlx->stepy;
		mlx->side = 1;
	}
	if (mlx->mapworld[mlx->mapx][mlx->mapy] > 0)
		mlx->hit = 1;
}

void	draw_all(t_mlx *mlx, int x)
{
	t_col col;

	init_color(&col);
	while (x++ < WIDTH)
	{
		init_calc(mlx, x);
		direction_wall(mlx);
		mlx->hit = 0;
		while (mlx->hit == 0)
			check_mouvement(mlx);
		if (mlx->side == 0)
			mlx->walldist = fabs((mlx->mapx - mlx->rayposx +
			(1 - mlx->stepx) / 2) / mlx->raydirx);
		else
			mlx->walldist = fabs((mlx->mapy - mlx->rayposy +
			(1 - mlx->stepy) / 2) / mlx->raydiry);
		mlx->lineheight = abs((int)(HEIGHT / mlx->walldist));
		mlx->dstart = -mlx->lineheight / 2 + HEIGHT / 2;
		if (mlx->dstart < 0)
			mlx->dstart = 0;
		mlx->dend = mlx->lineheight / 2 + HEIGHT / 2;
		if (mlx->dend >= HEIGHT)
			mlx->dend = HEIGHT - 1;
		draw_vert(mlx, &col, x);
	}
}
