/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 15:14:53 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/29 15:14:54 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	press_down(t_mlx *mlx)
{
	if (mlx->mapworld[(int)(mlx->posx -
		mlx->dirx * MOVESPEED)][(int)(mlx->posy)] == 0)
		mlx->posx -= mlx->dirx * MOVESPEED;
	if (mlx->mapworld[(int)(mlx->posx)][(int)(mlx->posy -
		mlx->diry * MOVESPEED)] == 0)
		mlx->posy -= mlx->diry * MOVESPEED;
	if (mlx->mapworld[(int)(mlx->posx -
		mlx->dirx * MOVESPEED)][(int)(mlx->posy)] == 3)
		mlx->posx = mlx->teleportx;
	if (mlx->mapworld[(int)(mlx->posx)][(int)(mlx->posy -
		mlx->diry * MOVESPEED)] == 3)
		mlx->posy = mlx->teleporty;
}

void	press_up(t_mlx *mlx)
{
	if (mlx->mapworld[(int)(mlx->posx +
		mlx->dirx * MOVESPEED)][(int)(mlx->posy)] == 0)
		mlx->posx += mlx->dirx * MOVESPEED;
	if (mlx->mapworld[(int)(mlx->posx)][(int)(mlx->posy +
		mlx->diry * MOVESPEED)] == 0)
		mlx->posy += mlx->diry * MOVESPEED;
	if (mlx->mapworld[(int)(mlx->posx +
		mlx->dirx * MOVESPEED)][(int)(mlx->posy)] == 3)
		mlx->posx = mlx->teleportx;
	if (mlx->mapworld[(int)(mlx->posx)][(int)(mlx->posy +
		mlx->diry * MOVESPEED)] == 3)
		mlx->posy = mlx->teleporty;
}

void	press_left(t_mlx *mlx)
{
	mlx->olddirx = mlx->dirx;
	mlx->dirx = mlx->dirx * cos(ROTSPEED) -
	mlx->diry * sin(ROTSPEED);
	mlx->diry = mlx->olddirx * sin(ROTSPEED) +
	mlx->diry * cos(ROTSPEED);
	mlx->oldplanex = mlx->planex;
	mlx->planex = mlx->planex * cos(ROTSPEED) -
	mlx->planey * sin(ROTSPEED);
	mlx->planey = mlx->oldplanex * sin(ROTSPEED) +
	mlx->planey * cos(ROTSPEED);
}

void	press_right(t_mlx *mlx)
{
	mlx->olddirx = mlx->dirx;
	mlx->dirx = mlx->dirx * cos(-ROTSPEED) -
	mlx->diry * sin(-ROTSPEED);
	mlx->diry = mlx->olddirx * sin(-ROTSPEED) +
	mlx->diry * cos(-ROTSPEED);
	mlx->oldplanex = mlx->planex;
	mlx->planex = mlx->planex * cos(-ROTSPEED) -
	mlx->planey * sin(-ROTSPEED);
	mlx->planey = mlx->oldplanex * sin(-ROTSPEED) +
	mlx->planey * cos(-ROTSPEED);
}

int		check_key_press(int keycode, t_mlx *mlx)
{
	mlx->key = keycode;
	if (mlx->menu == 1)
	{
		if (mlx->key == 126)
			press_up(mlx);
		if (mlx->key == 125)
			press_down(mlx);
		if (mlx->key == 124)
			press_right(mlx);
		if (mlx->key == 123)
			press_left(mlx);
		if (mlx->key >= 123 && mlx->key <= 126)
			mlx->move = 1;
	}
	return (0);
}
