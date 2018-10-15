/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:57:58 by kmayika           #+#    #+#             */
/*   Updated: 2018/09/11 10:42:55 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_split(char *str, t_wolf *wolf_mlx, int y)
{
	int		x;
	int		i;
	char	**line_tab;

	x = 0;
	i = 0;
	line_tab = ft_strsplit(str, ' ');
	while (line_tab[x] != NULL)
		x++;
	wolf_mlx->max_x = x;
	while (i < x)
	{
		wolf_mlx->map[y][i] = ft_atoi(line_tab[i]);
		i++;
	}
	while (x >= 1)
		ft_strdel(&line_tab[--x]);
	free(line_tab);
}

void	get_map(t_wolf *mlx, char *str)
{
	int		fd;
	char	*temp_line;
	int		y;

	y = 0;
	fd = open(str, O_RDONLY);
	if (fd >= 0)
	{
		while (get_next_line(fd, &temp_line) > 0)
		{
			ft_split(temp_line, mlx, y);
			y++;
			ft_strdel(&temp_line);
		}
		close(fd);
		mlx->max_y = y;
	}
	else
	{
		ft_putstr("\x1b[31m" "ERROR : Map not found\n");
		exit(1);
	}
}
