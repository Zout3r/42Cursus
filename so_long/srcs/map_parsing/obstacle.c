/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:46:10 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/15 13:21:23 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_coords(t_imgdata *data, size_t index, int32_t obs_index, \
																t_coords *obs)
{
	obs[obs_index].x_start = (index % (data->line.size + 1) * BLOK);
	obs[obs_index].y_start = (index / (data->line.size + 1)) * BLOK;
	obs[obs_index].x_end = ((index % (data->line.size + 1)) + 1) * BLOK;
	obs[obs_index].y_end = ((index / (data->line.size + 1)) + 1) * BLOK;
	obs[obs_index].instance = obs_index;
}

void	obstacle_pickup(t_imgdata *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	data->obs_pickup = ft_calloc(data->pickup_max, sizeof(t_coords));
	data->excep_pickup = ft_calloc(data->pickup_max, sizeof(bool) + 1);
	while (data->bigass[i])
	{
		if (data->bigass[i] == 'C')
			init_coords(data, i, j++, data->obs_pickup);
		i++;
	}
}
