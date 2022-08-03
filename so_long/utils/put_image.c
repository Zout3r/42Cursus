/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:00:52 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/03 14:58:25 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_vars ***v, int x, int y, char *img)
{
	(**v)->img = mlx_load_png(img);
	(**v)->img = mlx_texture_to_image((**v)->mlx, (**v)->img);
	mlx_image_to_window((**v)->mlx, (**v)->img, x, y);
}

void	put_image_to_map(char p, int x1, int y1, t_vars **v)
{
	if (p == '1')
		put_image(&v, x1, y1, "./img/muro.png");
	else if (p == 'C')
	{
		put_image(&v, x1, y1, "./img/suelo.png");
		put_image(&v, x1, y1, "./img/moneda.png");
		(*v)->collect++;
	}
	else if (p == 'E')
		put_image(&v, x1, y1, "./img/salida.png");
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		put_image(&v, x1, y1, "./img/suelo.png");
		put_image(&v, x1, y1, "./img/prota.png");
	}
	else
		put_image(&v, x1, y1, "./img/suelo.png");
}