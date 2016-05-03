/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 16:31:21 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/30 16:31:23 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"

void			choose_color(t_mlx *mlx, t_col *col)
{
	if (mlx->side == 1 && mlx->raydiry > 0)
		col->wall_col = 0xEAA326;
	else if (mlx->side == 1 && mlx->raydiry <= 0)
		col->wall_col = 0x25D98B;
	else if (mlx->side == 0 && mlx->raydirx > 0)
		col->wall_col = 0x58ADEF;
	else if (mlx->side == 0 && mlx->raydirx <= 0)
		col->wall_col = 0xBC6FE9;
}

unsigned int	swap_endian(unsigned int in)
{
	unsigned int	out;

	out = (in << 24);
	out |= ((in << 8) & 0x00ff0000);
	out |= ((in >> 8) & 0x0000ff00);
	out |= (in >> 24);
	return (out);
}

unsigned int	true_color(t_mlx *mlx, int rgb)
{
	unsigned int	color;

	color = mlx_get_color_value(mlx->ptr, rgb);
	if (mlx->endian == MLX_BIG_ENDIAN)
		color = swap_endian(color);
	return (color);
}
