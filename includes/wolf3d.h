/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 21:50:23 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/11 10:30:16 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define TILE_WIDTH 1000
# define TILE_HEIGHT 750

typedef struct		s_draw
{
	int				draw_start;
	int				draw_end;
	int				line_height;
}					t_draw;

typedef	struct		s_dist
{
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_y;
	double			delta_dist_x;
	double			perp_wall_dist;
}					t_dist;

typedef	struct		s_cam
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
}					t_cam;

typedef	struct		s_wolf
{
	void			*mlx;
	void			*win;
	void			*image;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			old_dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			old_plane_x;
	int				map[4096][4096];
	int				x;
	int				y;
	int				color;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				i;
	int				j;
	int				k;
	int				max_x;
	int				max_y;
	int				image_width;
	int				image_height;
	int				*image_data;
	struct s_cam	cam;
	struct s_dist	dist;
	struct s_draw	draw;
	char			*map_data;
}					t_wolf;

int					exit_prog(void);
int					hooks(int keycode, t_wolf *wolf_mlx);
void				mv_lhs(t_wolf *wolf_mlx);
void				mv_rhs(t_wolf *wolf_mlx);
void				mv_bkwd(t_wolf *wolf_mlx);
void				mv_fwrd(t_wolf *wolf_mlx);
void				render(t_wolf *wolf_mlx);
void				draw_line(t_wolf *wolf_mlx);
void				wall_hit(t_wolf *wolf_mlx);
void				get_dir(t_wolf *wolf_mlx);
void				color(t_wolf *wolf_mlx);
void				get_map(t_wolf *mlx, char *str);
void				ft_split(char *str, t_wolf *mlx, int y);
void				put_floor(t_wolf *wolf_mlx, int x);
void				put_menu(t_wolf *wolf_mlx);
void				error_checking(t_wolf *wolf_mlx);
void				map_border_err(t_wolf *wolf_mlx);
void				left_border_check(t_wolf *wolf_mlx);
void				top_border_check(t_wolf *wolf_mlx);
void				bottom_border_check(t_wolf *wolf_mlx);
#endif
