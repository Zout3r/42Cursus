/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:01:16 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/15 13:43:51 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	windowdisplay(t_imgdata *data, t_line *line, xpm_t **xpm)
{
	data->width = line->size * BLOK;
	data->height = (line->count * (BLOK)) + BLOK;
	if (data->width > 1920 || data->height > 960)
		return (ft_putendl_fd("Map is too big", STDOUT_FILENO), false);
	else if (data->width <= 1920 && data->width > 1536)
		xpm[BG] = mlx_load_xpm42("textures/bg_1920.xpm42");
	else if (data->width <= 1536 && data->width > 1280)
		xpm[BG] = mlx_load_xpm42("textures/bg_1536.xpm42");
	else if (data->width <= 1280 && data->width > 960)
		xpm[BG] = mlx_load_xpm42("textures/bg_1280.xpm42");
	else if (data->width <= 960 && data->width > 640)
		xpm[BG] = mlx_load_xpm42("textures/bg_960.xpm42");
	else if (data->width <= 640 && data->width > 313)
		xpm[BG] = mlx_load_xpm42("textures/bg_640.xpm42");
	else if (data->width <= 313)
		xpm[BG] = mlx_load_xpm42("textures/bg_313.xpm42");
	if (!xpm[BG])
		return (ft_putendl_fd("bg was not found", STDOUT_FILENO), false);
	return (true);
}

bool	loading_images(t_imgdata *data, xpm_t **xpm)
{
	data->mlx = mlx_init(data->width, data->height, "Joeguito", true);
	if (!data->mlx)
		return (0);
	xpm[TILE] = mlx_load_xpm42("textures/tile2.xpm42");
	if (!xpm[TILE])
		return (ft_putendl_fd("tile was not found", STDOUT_FILENO), false);
	xpm[WALL] = mlx_load_xpm42("textures/wall.xpm42");
	if (!xpm[WALL])
		return (ft_putendl_fd("wall was not found", STDOUT_FILENO), false);
	xpm[PICKUP] = mlx_load_xpm42("textures/pickup32.xpm42");
	if (!xpm[PICKUP])
		return (ft_putendl_fd("pickup was not found", STDOUT_FILENO), false);
	xpm[DOOR] = mlx_load_xpm42("textures/doortrans2.xpm42");
	if (!xpm[DOOR])
		return (ft_putendl_fd("door was not found", STDOUT_FILENO), false);
	xpm[CHAR_R] = mlx_load_xpm42("textures/main.xpm42");
	if (!xpm[CHAR_R])
		return (ft_putendl_fd("char was not found", STDOUT_FILENO), false);
	xpm[CHAR_L] = mlx_load_xpm42("textures/main_rev.xpm42");
	if (!xpm[CHAR_L])
		return (ft_putendl_fd("char_l was not found", STDOUT_FILENO), false);
	return (true);
}

bool	texture_to_image(t_imgdata *data, xpm_t **xpm, mlx_image_t **img)
{
	const uint32_t		wh2[] = {32, 32};
	const uint32_t		xy[] = {60, 40};

	img[BG] = mlx_texture_to_image(data->mlx, &xpm[BG]->texture);
	img[CHAR_R] = mlx_texture_area_to_image(data->mlx, \
						&xpm[CHAR_R]->texture, (uint32_t *)xy, (uint32_t *)wh2);
	img[TILE] = mlx_texture_to_image(data->mlx, &xpm[TILE]->texture);
	img[WALL] = mlx_texture_to_image(data->mlx, &xpm[WALL]->texture);
	img[PICKUP] = mlx_texture_to_image(data->mlx, &xpm[PICKUP]->texture);
	img[DOOR] = mlx_texture_to_image(data->mlx, &xpm[DOOR]->texture);
	if (!img[BG] || !img[CHAR_R] || !img[TILE] || !img[WALL] || !img[PICKUP] \
	|| !img[DOOR])
		return (ft_putendl_fd("Texture to image failed", STDOUT_FILENO), false);
	return (true);
}
