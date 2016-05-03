/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 16:37:05 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/30 16:37:06 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <fcntl.h>

static void check_player_map(t_mlx *mlx)
{
	if (mlx->player == 0)
	{
		ft_print_color(RED, "Error: Player not initialized\n", 2);
		exit (1);
	}
	if (mlx->map_ok == 0)
	{
		ft_print_color(RED, "Error: Map invalid\n", 2);
		exit (1);
	}
}

static void	change_data(t_mlx *mlx, char *str, int x)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			mlx->map_ok = 1;
		if (str[i] == 'P')
		{
			if (x <= 1)
			{
				ft_print_color(RED, "Error: P is on wrong place\n Player ", 2);
				ft_print_color(RED, "can't be on wall or on first row\n", 2);
				exit (1);
			}
			mlx->posx = x;
			mlx->posy = i;
			mlx->teleportx = x;
			mlx->teleporty = i;
			str[i] = '0';
			mlx->player = 1;
		}
		str[i] -= 48;
		i++;
	}
}

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	return (fd);
}

void		load_map(t_mlx *mlx, char *file)
{
	int		fd;
	int		count;
	int		x;
	char	*line;

	mlx->player = 0;
	mlx->map_ok = 0;
	fd = open_file(file);
	get_next_line(fd, &line);
	mlx->mapworld = (char **)malloc(sizeof(char *) * (ft_atoi(line) + 1));
	mlx->mapworld[ft_atoi(line)] = NULL;
	ft_strdel(&line);
	count = 0;
	x = 0;
	while (get_next_line(fd, &line))
	{
		mlx->mapworld[count] = ft_strdup(line);
		change_data(mlx, mlx->mapworld[count], x);
		ft_strdel(&line);
		count++;
		x++;
	}
	close(fd);
	ft_strdel(&line);
	check_player_map(mlx);
}
