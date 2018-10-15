/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:59:09 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/11 10:30:33 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	mv_fwrd(t_wolf *wolf_mlx)
{
	if (wolf_mlx->map[(int)(wolf_mlx->pos_y)]
	[(int)(wolf_mlx->pos_x + wolf_mlx->dir_x)] == 0)
		wolf_mlx->pos_x += wolf_mlx->dir_x;
	if (wolf_mlx->map[(int)(wolf_mlx->pos_y + wolf_mlx->dir_y)]
	[(int)(wolf_mlx->pos_x)] == 0)
		wolf_mlx->pos_y += wolf_mlx->dir_y;
}

void	mv_bkwd(t_wolf *wolf_mlx)
{
	if (wolf_mlx->map[(int)(wolf_mlx->pos_y)]
	[(int)(wolf_mlx->pos_x - wolf_mlx->dir_x)] == 0)
		wolf_mlx->pos_x -= wolf_mlx->dir_x;
	if (wolf_mlx->map[(int)(wolf_mlx->pos_y - wolf_mlx->dir_y)]
	[(int)(wolf_mlx->pos_x)] == 0)
		wolf_mlx->pos_y -= wolf_mlx->dir_y;
}

void	mv_rhs(t_wolf *wolf_mlx)
{
	wolf_mlx->old_dir_x = wolf_mlx->dir_x;
	wolf_mlx->dir_x = wolf_mlx->dir_x *
	cos(0.1) - wolf_mlx->dir_y *
	sin(0.1);
	wolf_mlx->dir_y = wolf_mlx->old_dir_x *
	sin(0.1) + wolf_mlx->dir_y *
	cos(0.1);
	wolf_mlx->old_plane_x = wolf_mlx->plane_x;
	wolf_mlx->plane_x = wolf_mlx->plane_x *
	cos(0.1) - wolf_mlx->plane_y *
	sin(0.1);
	wolf_mlx->plane_y = wolf_mlx->old_plane_x *
	sin(0.1) + wolf_mlx->plane_y *
	cos(0.1);
}

void	mv_lhs(t_wolf *wolf_mlx)
{
	wolf_mlx->old_dir_x = wolf_mlx->dir_x;
	wolf_mlx->dir_x = wolf_mlx->dir_x *
	cos(-0.1) - wolf_mlx->dir_y *
	sin(-0.1);
	wolf_mlx->dir_y = wolf_mlx->old_dir_x *
	sin(-0.1) + wolf_mlx->dir_y *
	cos(-0.1);
	wolf_mlx->old_plane_x = wolf_mlx->plane_x;
	wolf_mlx->plane_x = wolf_mlx->plane_x *
	cos(-0.1) - wolf_mlx->plane_y *
	sin(-0.1);
	wolf_mlx->plane_y = wolf_mlx->old_plane_x *
	sin(-0.1) + wolf_mlx->plane_y *
	cos(-0.1);
}
