/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 13:48:00 by etermeau          #+#    #+#             */
/*   Updated: 2015/04/14 13:49:03 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define MOVESPEED 0.2
# define ROTSPEED 0.2
# define WIDTH 1000
# define HEIGHT 850
# define KEYPRESSMASK (1L<<0)
# define KEYPRESS 2
# define MLX_BIG_ENDIAN 1

typedef struct	s_col
{
	int			sky_col;
	int			floor_col;
	int			wall_col;
}				t_col;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			wall_size;
	void		*img;
	char		*img_data;
	int			nb_pix;
	int			size_line;
	int			endian;
	int			color;
	int			key;
	char		**mapworld;
	void		*img_hand;
	void		*img_wand;
	void		*img_start;

	int			move;
	int			menu;
	int			player;
	int			map_ok;

	int			move_up;
	int			move_down;
	int			move_right;
	int			move_left;

	double		posx;
	double		posy;
	double		teleportx;
	double		teleporty;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		olddirx;
	double		oldplanex;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;

	int			mapx;
	int			mapy;

	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		walldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;

	int			lineheight;
	int			dstart;
	int			dend;
}				t_mlx;

void			put_menu(t_mlx *mlx);
void			print_select(t_mlx *mlx, int c, int x, int y);
void			init_calc(t_mlx *mlx, int x);
void			init_img(t_mlx *mlx);
void			init_mlx(t_mlx *mlx);
void			init_color(t_col *col);
void			choose_color(t_mlx *mlx, t_col *col);
void			draw_all(t_mlx *mlx, int x);
void			load_map(t_mlx *mlx, char *file);
int				check_key_press(int keycode, t_mlx *mlx);
void			draw_vert(t_mlx *mlx, t_col *col, int x);
unsigned int	true_color(t_mlx *mlx, int rgb);
unsigned int	swap_endian(unsigned int in);
void			image_pixel_put(t_mlx *mlx, int x, int y, int color);

#endif
