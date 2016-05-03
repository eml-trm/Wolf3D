/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 15:14:44 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/29 15:14:45 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"

void	image_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int pixel_index;
	int bytes_per_pixel;

	bytes_per_pixel = mlx->nb_pix / 8;
	bytes_per_pixel = mlx->nb_pix / 8;
	bytes_per_pixel = mlx->nb_pix / 8;
	pixel_index = y * mlx->size_line + x * bytes_per_pixel;
	ft_memcpy(mlx->img_data + pixel_index, &color, bytes_per_pixel);
}

void	draw_vert(t_mlx *mlx, t_col *col, int x)
{
	int a;
	int y;
	int e;

	a = 0;
	y = 0;
	mlx->wall_size = mlx->dend - mlx->dstart;
	e = (HEIGHT - mlx->wall_size - mlx->dstart);
	while (a++ < mlx->dstart)
	{
		mlx->color = true_color(mlx, col->sky_col);
		image_pixel_put(mlx, x, y++, mlx->color);
	}
	choose_color(mlx, col);
	while (mlx->wall_size > 0)
	{
		mlx->color = true_color(mlx, col->wall_col);
		image_pixel_put(mlx, x, y++, mlx->color);
		mlx->wall_size--;
	}
	while (e-- > 0)
	{
		mlx->color = true_color(mlx, col->floor_col);
		image_pixel_put(mlx, x, y++, mlx->color);
	}
}
