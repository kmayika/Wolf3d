/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:13:15 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/22 15:13:15 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main(/*int ac, char **av*/)
{
	double pos_x = 22, pos_y = 12;//x and y start positions
	double dir_x = - 1, dir_y = 0;// initial direction vector
	double plane_x = 0, plan_y = 0.66;//camera plane
	double time = 0;//time of current frame
	double old_time = 0; //time of old frame
	int	x = 0;
	int	w;

	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500,500, "Wolf3D");
	while (1)
	{
		while(x < w)
		{
			double camera_x = 2 * x / double(w) - 1;
			double ray_dir_x = dir_x + plane_x * camera_x;
			double ray_dir_y = dir_y + plan_y * camera_x;
 
}

	}
	mlx_loop(mlx);
}
