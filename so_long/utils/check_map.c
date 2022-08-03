/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:20:29 by jperez-p          #+#    #+#             */
/*   Updated: 2022/07/25 14:40:33 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_vars ***v, char *err)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	ft_printf("%s", err);
	exit(1);
}

static void	check_rectangular(t_vars **vars)
{
	int	y_map;
	int	x_map;
	int	height;
	int	backup;

	y_map = 0;
	backup = 0;
	height = get_height((*vars)->map);
	while (y_map != height)
	{
		x_map = 0;
		while ((*vars)->map[y_map][x_map] != '\0')
			x_map++;
		y_map++;
		if (backup != 0)
		{
			if (backup != x_map)
				ft_error(&vars, "Error: El mapa no es rectangular");
		}
		else
			backup = x_map;
	}
}

static int	check_line(char *line)
{
	int	count;

	count = 0;
	while (line[count] != '\0')
	{
		if (line[count] != '1')
			return (1);
		count++;
	}
	return (0);
}

static void	surrender_walls(t_vars **v)
{
	int		count;
	char	*err;

	err = "Error: El mapa no está rodeado por muros";
	if (check_line((*v)->map[0]))
		ft_error(&v, err);
	count = get_height((*v)->map) - 1;
	while (count)
	{
		if ((*v)->map[count][0] != '1' ||
			(*v)->map[count][ft_strlen((*v)->map[count]) - 1] != '1')
		{
			ft_error(&v, err);
		}
		count--;
	}
	if (check_line((*v)->map[get_height((*v)->map) - 1]))
		ft_error(&v, err);
}

void	check_map(t_vars *vars)
{
	check_rectangular(&vars);
	surrender_walls(&vars);
	check_elements(&vars);
}