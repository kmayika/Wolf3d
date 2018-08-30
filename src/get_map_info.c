/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:57:58 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/30 14:09:40 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_split(char *str, t_wolf *mlx, int y)
{
	int		x;
	int		i;
	char	**line_tab;

	x = 0;
	i = 0;
	line_tab = ft_strsplit(str, ' ');
	while (line_tab[x] != NULL)
		x++;
	while (i < x)
	{
		mlx->map[y][i] = ft_atoi(line_tab[i]);
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
	while (get_next_line(fd, &temp_line) > 0)
	{
		ft_split(temp_line, mlx, y);
		y++;
		ft_strdel(&temp_line);
	}
	close(fd);
}
