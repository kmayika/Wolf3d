/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:58:31 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/30 14:33:54 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	color(t_wolf *wolf_mlx)
{
	if (wolf_mlx->map[wolf_mlx->map_y][wolf_mlx->map_x] == 1)
		wolf_mlx->color = 0xFFFFFF;
	else if (wolf_mlx->map[wolf_mlx->map_y][wolf_mlx->map_x] == 2)
		wolf_mlx->color = 0xFF00FF;
	else if (wolf_mlx->map[wolf_mlx->map_y][wolf_mlx->map_x] == 3)
		wolf_mlx->color = 0xF0FF0F;
	else if (wolf_mlx->map[wolf_mlx->map_y][wolf_mlx->map_x] == 4)
		wolf_mlx->color = 0xFFFF00;
	else if (wolf_mlx->map[wolf_mlx->map_y][wolf_mlx->map_x] == 5)
		wolf_mlx->color = 0xFf0ff0;
	else
		wolf_mlx->color = 0xFFFF00;
	if (wolf_mlx->side == 1 && wolf_mlx->map[wolf_mlx->map_y]
	[wolf_mlx->map_x] != 1)
		wolf_mlx->color /= 1.5;
}
