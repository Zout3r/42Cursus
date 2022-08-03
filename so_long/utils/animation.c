/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:53:09 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/03 15:09:25 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_img(t_vars **vars)
{
	(*vars)->e_vars.imgs[0] = "./img/enemigo.png";
	(*vars)->e_vars.imgs[1] = "./img/enemigo.png";
	(*vars)->e_vars.imgs[2] = "./img/enemigo.png";
	(*vars)->e_vars.imgs[3] = "./img/enemigo.png";
	(*vars)->e_vars.imgs[4] = "./img/enemigo.png";
	(*vars)->img = mlx_load_png("./img/suelo.png");
	(*vars)->img = mlx_texture_to_image((*vars)->mlx, (*vars)->img);
	mlx_image_to_window((*vars)->mlx, (*vars)->img,
		(*vars)->e_vars.x_e * 50, (*vars)->e_vars.y_e * 50);
	(*vars)->img = mlx_load_png((*vars)->e_vars.imgs[(*vars)->e_vars.x]);
	(*vars)->img = mlx_texture_to_image((*vars)->mlx,
			(*vars)->img);
	mlx_image_to_window(
		(*vars)->mlx, (*vars)->img, (*vars)->e_vars.x_e * 50,
		(*vars)->e_vars.y_e * 50);
}

void	move_enemy(t_vars **vars)
{
	(*vars)->img = mlx_load_png("./img/suelo.png");
	(*vars)->img = mlx_texture_to_image((*vars)->mlx, (*vars)->img);
	mlx_image_to_window((*vars)->mlx, (*vars)->img,
		(*vars)->e_vars.x_e * 50, (*vars)->e_vars.y_e * 50);
	if ((*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != '1' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != 'C' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != 'E' &&
		(*vars)->e_vars.path_to_move == 0)
		(*vars)->e_vars.x_e++;
	else
		(*vars)->e_vars.path_to_move = 1;
	if ((*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != '1' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != 'C' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != 'E' &&
		(*vars)->e_vars.path_to_move == 1)
		(*vars)->e_vars.x_e--;
	else
		(*vars)->e_vars.path_to_move = 0;
}

static void	ft_lose(t_vars **v, char *err)
{
	int	x;

	x = 0;
	while ((*v)->map[x])
	{
		free((*v)->map[x]);
		x++;
	}
	free((*v)->map);
	ft_printf("s", err);
	exit(0);
}

int	animation(t_vars *vars)
{
	if (get_position_for_enemy(&vars) != 0)
	{
		if (vars->e_vars.sleep-- <= 0)
		{
			vars->e_vars.x++;
			vars->e_vars.sleep = 5;
		}
		if (vars->e_vars.x == 3)
			vars->e_vars.x = 0;
		if (vars->e_vars.sleep_for_move-- <= 0)
		{
			move_enemy(&vars);
			vars->e_vars.sleep_for_move = 30;
		}
		if ((vars->e_vars.y_e == vars->y_p / 50)
			&& (vars->e_vars.x_e == vars->x_p / 50))
		{
			ft_lose(&vars, "Ere un tieso");
		}
		render_img(&vars);
	}
	if (vars->collect <= 0)
		open_exit(&vars);
	return (0);
}