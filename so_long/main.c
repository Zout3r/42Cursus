/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:38:42 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/03 15:39:53 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	int	x;

	if (keycode == 2 || keycode == 124)
		to_right(&vars);
	else if (keycode == 0 || keycode == 123)
		to_left(&vars);
	else if (keycode == 13 || keycode == 126)
		to_up(&vars);
	else if (keycode == 1 || keycode == 125)
		to_down(&vars);
	else if (keycode == 53)
	{
		x = 0;
		while (vars->map[x])
		{
			free(vars->map[x]);
			x++;
		}
		free(vars->map);
		mlx_terminate(vars->mlx);
		exit(1);
	}
	return (0);
}

int	ft_exit(t_vars *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_terminate(v->mlx);
	exit(1);
	return (0);
}

void	render_map(t_vars *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1= 0;
	y_map = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->win_w > 0)
		{
			put_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 50;
			vars->win_w--;
		}
		vars->win_w = backup_w;
		y_map++;
		y1 += 50;
		vars->win_h--;
	}
}

static void	init_vars(t_vars *vars)
{
	vars->collect = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
	vars->e_vars.sign = 1;
	vars->e_vars.x = 0;
	vars->e_vars.sleep = 5;
	vars->e_vars.sleep_for_move = 60;
	vars->e_vars.path_to_move = 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc <= 1)
	{
		perror("Falta el mapa");
		exit(1);
	}
	(void)argv;
	check_file(argv[1]);
	vars.map = get_map(argv[1]);
	if (vars.map != NULL)
	{
		check_map(&vars);
		init_vars(&vars);
		vars.mlx = mlx_init(vars.win_w * 50, vars.win_h * 50, "So_Long", true);
		vars.win = mlx_new_image(vars.mlx,
				vars.win_w * 50, vars.win_h * 50);
		render_map(&vars);
		if (mlx_is_key_down(vars.mlx, 27))
			ft_exit(&vars);
		mlx_put_string(vars.mlx, "Move: 0", 5, 10);
		//mlx_loop_hook(vars.mlx, animation, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
/* mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*prota;
	mlx_image_t		*protap;
	int				x;
	int				y;

	x = 0;
	y = 0;
	mlx = mlx_init(900, 800, "MLX 42", true);
	img = mlx_new_image(mlx, 900, 800);
	mlx_image_to_window(mlx, img, 0, 0);
	prota = mlx_load_png("./img/muro.png");
	protap = mlx_texture_to_image(mlx, prota);
	while (x <= 600)
	{
		mlx_image_to_window(mlx, protap, x, 0);
		x = x + 50;
	}
	x = 0;
	y = 150;
	prota = mlx_load_png("./img/suelo.png");
	protap = mlx_texture_to_image(mlx, prota);
	while (x <= 500 && y <= 500)
	{
		mlx_image_to_window(mlx, protap, x, y);
		x = x + 150;
		y = y + 150;
	}
	prota = mlx_load_png("./img/enemigo.png");
	protap = mlx_texture_to_image(mlx, prota);
	mlx_image_to_window(mlx, protap, 0, 150);
	prota = mlx_load_png("./img/prota.png");
	protap = mlx_texture_to_image(mlx, prota);
	mlx_image_to_window(mlx, protap, 200, 150);
	prota = mlx_load_png("./img/moneda.png");
	protap = mlx_texture_to_image(mlx, prota);
	mlx_image_to_window(mlx, protap, 500, 150);
	prota = mlx_load_png("./img/salida.png");
	protap = mlx_texture_to_image(mlx, prota);
	mlx_image_to_window(mlx, protap, 500, 300);
	mlx_loop(mlx); */