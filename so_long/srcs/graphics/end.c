/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:51:39 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/15 13:20:28 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	terminate(t_imgdata *data)
{
	mlx_delete_image(data->mlx, data->img[GREY]);
	mlx_delete_image(data->mlx, data->img[SCREEN]);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free_2d(data->map);
	free(data->bigass);
	exit(1);
}

void	end(mlx_key_data_t keydata, void *data)
{
	t_imgdata *const	data2 = data;

	if (mlx_is_key_down(data2->mlx, keydata.key))
		terminate(data);
}
