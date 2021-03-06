/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:13:15 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/11 11:38:19 by kmayika          ###   ########.fr       */
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
	draw_line(wolf_mlx);
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

void	put_menu(t_wolf *wolf_mlx)
{
	mlx_string_put(wolf_mlx->mlx, wolf_mlx->win,
	10, 10, 0x000000, "CONTROLS");
	mlx_string_put(wolf_mlx->mlx, wolf_mlx->win,
	10, 25, 0x000000, "MOVE FWD  : UP ARROW");
	mlx_string_put(wolf_mlx->mlx, wolf_mlx->win,
	10, 40, 0x000000, "MOVE BKWD : DOWN ARROW");
	mlx_string_put(wolf_mlx->mlx, wolf_mlx->win,
	10, 55, 0x000000, "MOVE RGT  : RIGHT ARROW");
	mlx_string_put(wolf_mlx->mlx, wolf_mlx->win,
	10, 70, 0x000000, "MOVE LFT  : LEFT ARROW");
	mlx_string_put(wolf_mlx->mlx, wolf_mlx->win,
	10, 85, 0x000000, "CLOSE     : ESC");
}

void	error_checking(t_wolf *wolf_mlx)
{
	if (ft_strcmp(wolf_mlx->map_data, "wolf_maps/map_1.wolf") == 0 ||
	ft_strcmp(wolf_mlx->map_data, "wolf_maps/level2.wolf") == 0)
	{
		wolf_mlx->mlx = mlx_init();
		wolf_mlx->win = mlx_new_window(wolf_mlx->mlx, TILE_WIDTH,
		TILE_HEIGHT, "Wolf3D");
		get_map(wolf_mlx, wolf_mlx->map_data);
		if (wolf_mlx->map[(int)wolf_mlx->pos_y][(int)(wolf_mlx->pos_x)] > 0 ||
		wolf_mlx->map[(int)wolf_mlx->pos_y - 1][(int)(wolf_mlx->pos_x)] > 0 ||
		wolf_mlx->map[(int)wolf_mlx->pos_y][(int)(wolf_mlx->pos_x - 1)] > 0)
		{
			ft_putstr("\x1b[31m" "ERROR : Invalid starting position in map\n");
			exit(1);
		}
		map_border_err(wolf_mlx);
		render(wolf_mlx);
		mlx_hook(wolf_mlx->win, 2, 0, hooks, wolf_mlx);
		mlx_hook(wolf_mlx->win, 17, 0, exit_prog, 0);
		mlx_loop(wolf_mlx->mlx);
	}
	else
	{
		ft_putstr("\x1b[31m" "ERROR : Map not compatible\n");
		exit(1);
	}
}

int		main(int ac, char **av)
{
	t_wolf *wolf_mlx;

	wolf_mlx = (t_wolf *)malloc(sizeof(t_wolf));
	if (ac == 2)
	{
		wolf_mlx->pos_x = 2.1;
		wolf_mlx->pos_y = 2.1;
		wolf_mlx->dir_x = 1;
		wolf_mlx->dir_y = 0;
		wolf_mlx->plane_x = 0;
		wolf_mlx->plane_y = 0.60;
		wolf_mlx->x = 0;
		wolf_mlx->image_height = TILE_HEIGHT;
		wolf_mlx->image_width = TILE_WIDTH;
		wolf_mlx->map_data = av[1];
		error_checking(wolf_mlx);
	}
	ft_putstr("\x1b[31m" "ERROR : Too many arguments\n");
	return (0);
}
