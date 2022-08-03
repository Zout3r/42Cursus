/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:16:02 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/03 15:40:26 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	collected(t_vars ***v)
{
	(**v)->collect--;
	(**v)->map[((**v)->y_p / 50)][((**v)->x_p / 50)] = '0';
	(**v)->img = mlx_load_png("./img/suelo.png");
	(**v)->img = mlx_texture_to_image((**v)->mlx, (**v)->img);
	mlx_image_to_window((**v)->mlx, (**v)->img, (**v)->x_p, (**v)->y_p);
}

void	to_left(t_vars **v)
{
	(*v)->img = mlx_load_png("./img/suelo.png");
	(*v)->img = mlx_texture_to_image((*v)->mlx, (*v)->img);
	mlx_image_to_window((*v)->mlx, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) - 1] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) - 1] != '1')
	{
		(*v)->x_p -= 50;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
		collected(&v);
	(*v)->img = mlx_load_png("./img/prota.png");
	(*v)->img = mlx_texture_to_image((*v)->mlx, (*v)->img);
	mlx_image_to_window((*v)->mlx, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_right(t_vars **v)
{
	(*v)->img = mlx_load_png("./img/suelo.png");
	(*v)->img = mlx_texture_to_image((*v)->mlx, (*v)->img);
	mlx_image_to_window((*v)->mlx, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) + 1] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) + 1] != '1')
	{
		(*v)->x_p -= 50;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
		collected(&v);
	(*v)->img = mlx_load_png("./img/prota.png");
	(*v)->img = mlx_texture_to_image((*v)->mlx, (*v)->img);
	mlx_image_to_window((*v)->mlx, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_up(t_vars **v)
{
	(*v)->img = mlx_load_png("./img/suelo.png");
	(*v)->img = mlx_texture_to_image((*v)->mlx, (*v)->img);
	mlx_image_to_window((*v)->mlx, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 50 - 1)][((*v)->x_p / 50)] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 50) - 1][((*v)->x_p / 50)] != '1')
	{
		(*v)->x_p -= 50;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
		collected(&v);
	(*v)->img = mlx_load_png("./img/prota.png");
	(*v)->img = mlx_texture_to_image((*v)->mlx, (*v)->img);
	mlx_image_to_window((*v)->mlx, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_down(t_vars **v)
{
	(*v)->img = mlx_load_png("./img/suelo.png");
	(*v)->img = mlx_texture_to_image((*v)->mlx, (*v)->img);
	mlx_image_to_window((*v)->mlx, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 50 + 1)][((*v)->x_p / 50)] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 50) + 1][((*v)->x_p / 50)] != '1')
	{
		(*v)->x_p -= 50;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
		collected(&v);
	(*v)->img = mlx_load_png("./img/prota.png");
	(*v)->img = mlx_texture_to_image((*v)->mlx, (*v)->img);
	mlx_image_to_window((*v)->mlx, (*v)->img, (*v)->x_p, (*v)->y_p);
}