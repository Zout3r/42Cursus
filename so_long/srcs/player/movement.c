/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:45:14 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/15 15:59:34 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_imgdata *data, size_t x, size_t y)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) \
					&& data->map[y + 1][x] != '1')
	data->img[CHAR_R]->instances[0].y += 4;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A) \
							&& data->map[y][x] != '1')
		data->img[CHAR_R]->instances[0].x -= 4;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D) \
							&& data->map[y][x + 1] != '1')
		data->img[CHAR_R]->instances[0].x += 4;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W) \
		&& data->map[y][x] != '1' && (data->fly == true || \
		GRAV == 0))
		data->img[CHAR_R]->instances[0].y -= 4;
}

void	movecounter(t_imgdata *data, size_t x, size_t y)
{
	if ((mlx_is_key_down(data->mlx, MLX_KEY_S) || mlx_is_key_down \
		(data->mlx, MLX_KEY_D) || mlx_is_key_down (data->mlx, MLX_KEY_A) \
		|| mlx_is_key_down(data->mlx, MLX_KEY_W)) && \
		(x >= data->old_x + BLOK || x <= data->old_x - BLOK \
			|| y >= data->old_y + BLOK || y <= data->old_y - BLOK))
	{
		data->old_x = x;
		data->old_y = y;
		write(1, "movement: ", 10);
		ft_putnbr_fd(data->count[MOVE], 1);
		write(1, "\n", 1);
		data->count[MOVE]++;
	}
}
