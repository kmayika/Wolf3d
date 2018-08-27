/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 21:50:23 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/27 14:43:21 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

#include <mlx.h>
//#include "../../../../minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#define mapWidth 24
#define mapHeight 24
#define TILE_WIDTH 1000
#define TILE_HEIGHT 1000

typedef struct	s_draw
{
	int		draw_start;
	int		draw_end;
	int		line_height;
}				t_draw;

typedef	struct	s_dist
{
	double side_dist_x;
	double side_dist_y;
	double delta_dist_y;
	double delta_dist_x;
	double perp_wall_dist;
}				t_dist;

typedef	struct	s_cam
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
}				t_cam;

typedef	struct s_wolf
{
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	old_dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	old_plane_x;
	int		x;
	int		y;
	int		color;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	struct	s_cam	cam;
	struct	s_dist	dist;
	struct	s_draw	draw;
	

}				t_wolf;

#endif
