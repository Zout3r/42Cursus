/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_paco.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:41:30 by jperez-p          #+#    #+#             */
/*   Updated: 2022/07/26 16:55:49 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_err_message(t_map_vars *map)
{
	if (map->c == 0)
		return ("Error: Falta elemento 'C'");
	if (map->p == 0)
		return ("Error: Falta elemento 'P'");
	if (map->e == 0)
		return ("Error: Falta elemento 'E'");
	if (map->p > 1)
		return ("Error: Hay más de un elemento 'P'");
	return ("Error: Falta algún elemento en el mapa");
}

char	*unknown_element(t_vars ***v, char c)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	ft_printf("Error: Elemento desconocido %c", c);
	exit(1);
}

void	check_elements(t_vars **vars)
{
	t_map_vars	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height((*vars)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*vars)->map[map.y][map.x] != '\0')
		{
			if ((*vars)->map[map.y][map.x] == 'E')
				map.e++;
			if ((*vars)->map[map.y][map.x] == 'P')
				map.p++;
			if ((*vars)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*vars)->map[map.y][map.x] != '1' &&
				(*vars)->map[map.y][map.x] != '0')
				unknown_element(&vars, (*vars)->map[map.y][map.x]);
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
		ft_error(&vars, ft_err_message(&map));
}