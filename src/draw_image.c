/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:58:12 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/03 14:13:44 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_line(t_wolf *wolf_mlx)
{
	if (wolf_mlx->side == 0)
		wolf_mlx->dist.perp_wall_dist = (wolf_mlx->map_x - wolf_mlx->pos_x +
		(1 - wolf_mlx->step_x) / 2) / wolf_mlx->cam.ray_dir_x;
	else
		wolf_mlx->dist.perp_wall_dist = (wolf_mlx->map_y - wolf_mlx->pos_y +
		(1 - wolf_mlx->step_y) / 2) / wolf_mlx->cam.ray_dir_y;
	wolf_mlx->draw.line_height =
	(int)(TILE_HEIGHT / wolf_mlx->dist.perp_wall_dist);
	wolf_mlx->draw.draw_start =
	-wolf_mlx->draw.line_height / 2 + TILE_HEIGHT / 2;
	if (wolf_mlx->draw.draw_start < 0)
		wolf_mlx->draw.draw_start = 0;
	wolf_mlx->draw.draw_end =
	wolf_mlx->draw.line_height / 2 + TILE_HEIGHT / 2;
	if (wolf_mlx->draw.draw_end >= TILE_HEIGHT)
		wolf_mlx->draw.draw_end = TILE_HEIGHT - 1;
	while (wolf_mlx->draw.draw_start != wolf_mlx->draw.draw_end)
	{
		color(wolf_mlx);
		wolf_mlx->image_data[(wolf_mlx->draw.draw_start *
		wolf_mlx->image_width) + wolf_mlx->x] = wolf_mlx->color;
		wolf_mlx->draw.draw_start++;
	}
}

void	render(t_wolf *wolf_mlx)
{
	wolf_mlx->x = 0;
	wolf_mlx->image = mlx_new_image(wolf_mlx->mlx,
	wolf_mlx->image_width, wolf_mlx->image_height);
	wolf_mlx->image_data = (int *)mlx_get_data_addr(wolf_mlx->image,
	&wolf_mlx->i, &wolf_mlx->j, &wolf_mlx->k);
	while (wolf_mlx->x < TILE_WIDTH)
	{
		wolf_mlx->cam.camera_x = 2 * wolf_mlx->x / (double)TILE_WIDTH - 1;
		wolf_mlx->cam.ray_dir_x = wolf_mlx->dir_x + wolf_mlx->plane_x *
		wolf_mlx->cam.camera_x;
		wolf_mlx->cam.ray_dir_y = wolf_mlx->dir_y + wolf_mlx->plane_y *
		wolf_mlx->cam.camera_x;
		wolf_mlx->map_x = (int)wolf_mlx->pos_x;
		wolf_mlx->map_y = (int)wolf_mlx->pos_y;
		wolf_mlx->dist.delta_dist_x = fabs(1 / wolf_mlx->cam.ray_dir_x);
		wolf_mlx->dist.delta_dist_y = fabs(1 / wolf_mlx->cam.ray_dir_y);
		wolf_mlx->hit = 0;
		get_dir(wolf_mlx);
		wall_hit(wolf_mlx);
		draw_line(wolf_mlx);
		wolf_mlx->x++;
	}
	mlx_put_image_to_window(wolf_mlx->mlx, wolf_mlx->win,
	wolf_mlx->image, 0, 0);
	mlx_destroy_image(wolf_mlx->mlx, (char *)wolf_mlx->image);
}
