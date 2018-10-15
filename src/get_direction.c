/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:13:34 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/11 11:35:55 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	get_dir(t_wolf *wolf_mlx)
{
	if (wolf_mlx->cam.ray_dir_x < 0)
	{
		wolf_mlx->step_x = -1;
		wolf_mlx->dist.side_dist_x = (wolf_mlx->pos_x - wolf_mlx->map_x) *
		wolf_mlx->dist.delta_dist_x;
	}
	else
	{
		wolf_mlx->step_x = 1;
		wolf_mlx->dist.side_dist_x = (wolf_mlx->map_x + 1.0 - wolf_mlx->pos_x) *
		wolf_mlx->dist.delta_dist_x;
	}
	if (wolf_mlx->cam.ray_dir_y < 0)
	{
		wolf_mlx->step_y = -1;
		wolf_mlx->dist.side_dist_y = (wolf_mlx->pos_y - wolf_mlx->map_y) *
		wolf_mlx->dist.delta_dist_y;
	}
	else
	{
		wolf_mlx->step_y = 1;
		wolf_mlx->dist.side_dist_y = (wolf_mlx->map_y + 1.0 - wolf_mlx->pos_y) *
		wolf_mlx->dist.delta_dist_y;
	}
}
