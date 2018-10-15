/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:20:00 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/11 10:41:31 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	map_border_err(t_wolf *wolf_mlx)
{
	int		y;

	y = -1;
	while (++y < wolf_mlx->max_y)
	{
		if (wolf_mlx->map[y][wolf_mlx->max_x - 1] == 0)
		{
			ft_putstr("\x1b[31m" "ERROR : Map invalid\n");
			exit(1);
		}
	}
	left_border_check(wolf_mlx);
}

void	left_border_check(t_wolf *wolf_mlx)
{
	int		y;

	y = -1;
	while (++y < wolf_mlx->max_y)
	{
		if (wolf_mlx->map[y][0] == 0)
		{
			ft_putstr("\x1b[31m" "ERROR : Map invalid\n");
			exit(1);
		}
	}
	top_border_check(wolf_mlx);
}

void	top_border_check(t_wolf *wolf_mlx)
{
	int		x;

	x = 0;
	while (x < wolf_mlx->max_x)
	{
		if (wolf_mlx->map[0][x++] == 0)
		{
			ft_putstr("\x1b[31m" "ERROR : Map invalid\n");
			exit(1);
		}
	}
	bottom_border_check(wolf_mlx);
}

void	bottom_border_check(t_wolf *wolf_mlx)
{
	int		x;

	x = 0;
	while (x < wolf_mlx->max_x)
	{
		if (wolf_mlx->map[wolf_mlx->max_y - 1][x++] == 0)
		{
			ft_putstr("\x1b[31m" "ERROR : Map invalid\n");
			exit(1);
		}
	}
}
