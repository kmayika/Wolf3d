/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:57:42 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/11 10:30:54 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		exit_prog(void)
{
	exit(1);
}

int		hooks(int keycode, t_wolf *wolf_mlx)
{
	if (keycode == 53)
		exit_prog();
	else if (keycode == 126)
	{
		mv_fwrd(wolf_mlx);
	}
	else if (keycode == 125)
	{
		mv_bkwd(wolf_mlx);
	}
	else if (keycode == 123)
	{
		mv_lhs(wolf_mlx);
	}
	else if (keycode == 124)
	{
		mv_rhs(wolf_mlx);
	}
	mlx_clear_window(wolf_mlx->mlx, wolf_mlx->win);
	render(wolf_mlx);
	return (0);
}
