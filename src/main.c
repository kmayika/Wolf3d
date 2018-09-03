/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:13:15 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/03 14:03:55 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wall_hit(t_wolf *wolf_mlx)
{
	while (wolf_mlx->hit == 0)
	{
		if (wolf_mlx->dist.side_dist_x < wolf_mlx->dist.side_dist_y)
		{
			wolf_mlx->dist.side_dist_x += wolf_mlx->dist.delta_dist_x;
			wolf_mlx->map_x += wolf_mlx->step_x;
			wolf_mlx->side = 0;
		}
		else
		{
			wolf_mlx->dist.side_dist_y += wolf_mlx->dist.delta_dist_y;
			wolf_mlx->map_y += wolf_mlx->step_y;
			wolf_mlx->side = 1;
		}
		if (wolf_mlx->map[wolf_mlx->map_y][wolf_mlx->map_x] > 0)
			wolf_mlx->hit = 1;
	}
	put_floor(wolf_mlx, wolf_mlx->x);
}

void	put_floor(t_wolf *wolf_mlx, int x)
{
	int		m;
	int		n;
	int		k;

	m = wolf_mlx->draw.draw_start * TILE_WIDTH + x;
	n = wolf_mlx->draw.draw_end * TILE_WIDTH + x;
	k = x;
	while (k <= m)
	{
		wolf_mlx->image_data[k] = 0x0CCFFFF;
		k += TILE_WIDTH;
	}
	k = (TILE_HEIGHT * TILE_WIDTH + x) - TILE_WIDTH;
	while (k >= n)
	{
		wolf_mlx->image_data[k] = 0x0808080;
		k -= TILE_WIDTH;
	}
}

int		main(int ac, char **av)
{
	t_wolf *wolf_mlx;

	wolf_mlx = (t_wolf *)malloc(sizeof(t_wolf));
	if (ac == 2)
	{
		wolf_mlx->pos_x = 2;
		wolf_mlx->pos_y = 2;
		wolf_mlx->dir_x = 1;
		wolf_mlx->dir_y = 0;
		wolf_mlx->plane_x = 0;
		wolf_mlx->plane_y = 0.66;
		wolf_mlx->x = 0;
		wolf_mlx->y = 0;
		wolf_mlx->image_height = TILE_HEIGHT;
		wolf_mlx->image_width = TILE_WIDTH;
		wolf_mlx->mlx = mlx_init();
		wolf_mlx->win = mlx_new_window(wolf_mlx->mlx, TILE_WIDTH,
		TILE_HEIGHT, "Wolf3D");
		get_map(wolf_mlx, av[1]);
		render(wolf_mlx);
		mlx_hook(wolf_mlx->win, 2, 0, hooks, wolf_mlx);
		mlx_hook(wolf_mlx->win, 17, 0, exit_prog, 0);
		mlx_loop(wolf_mlx->mlx);
	}
	return (0);
}
