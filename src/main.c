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

#include "../../../../minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		main(/*int ac, char **av*/)
{
	double pos_x = 22, pos_y = 12;//x and y start positions
	double dir_x = - 1, dir_y = 0;// initial direction vector
	double plane_x = 0, plane_y = 0.66;//camera plane
//	double time = 0;//time of current frame
//	double old_time = 0; //time of old frame
	int	x = 0;
	int y = 0;

	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500,500, "Wolf3D");
	while (y < 500)
	{
		while(x < 500)
		{
			double camera_x = 2 * x / 500 - 1;
			double rayDirX = dir_x + plane_x * camera_x;
			double rayDirY = dir_y + plane_y * camera_x;
			//which box of the map we're in
      		int mapX = (int)pos_x;
      		int mapY = (int)pos_y;

      	//length of ray from current position to next x or y-side
      		double sideDistX;
      		double sideDistY;

       	//length of ray from one x or y-side to next x or y-side
      		double deltaDistX = fabs(1 / rayDirX);
     		double deltaDistY = fabs(1 / rayDirY);
      		double perpWallDist;

      	//what direction to step in x or y-direction (either +1 or -1)
      		int stepX;
      		int stepY;

      		int hit = 0; //was there a wall hit?
      		int side; //was a NS or a EW wall hit?
			//calculate step and initial sideDist
			if (rayDirX < 0)
     		{
        	stepX = -1;
        	sideDistX = (pos_x - mapX) * deltaDistX;
      		}
      		else
      		{
				stepX = 1;
        		sideDistX = (mapX + 1.0 - pos_x) * deltaDistX;
      		}
      		if (rayDirY < 0)
     		{
        		stepY = -1;
        		sideDistY = (pos_y - mapY) * deltaDistY;
      		}
      		else
      		{
        		stepY = 1;
        		sideDistY = (mapY + 1.0 - pos_y) * deltaDistY;
      		}
			//perform DDA
      		while (hit == 0)
      		{
        //jump to next map square, OR in x-direction, OR in y-direction
        		if (sideDistX < sideDistY)
        		{
          			sideDistX += deltaDistX;
          			mapX += stepX;
          			side = 0;
       			}
        		else
        		{
          			sideDistY += deltaDistY;
          			mapY += stepY;
          			side = 1;
        		}
        //Check if ray has hit a wall
        		if (worldMap[mapX][mapY] > 0)
					hit = 1;
      		}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      		if (side == 0)
			  perpWallDist = (mapX - pos_x + (1 - stepX) / 2) / rayDirX;
      		else
			  perpWallDist = (mapY - pos_y + (1 - stepY) / 2) / rayDirY;
			//Calculate height of line to draw on screen
      		int lineHeight = (int)(500 / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      		int drawStart = -lineHeight / 2 + 500 / 2;
      		if(drawStart < 0)
			  	drawStart = 0;
      		int drawEnd = lineHeight / 2 + 500 / 2;
      		if(drawEnd >= 500)
	  			drawEnd = 500 - 1;
			mlx_pixel_put(mlx,win,drawStart,drawEnd, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
}
