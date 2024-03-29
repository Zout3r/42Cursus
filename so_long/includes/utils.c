/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:52:43 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/09 18:56:24 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2d(char **map)
{
	while (*map)
	{
		free(*map);
		map++;
	}
	return ;
}

bool	free_array(mlx_image_t **arr, char *str, t_imgdata *data)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	ft_putendl_fd(str, STDOUT_FILENO);
	while (arr)
	{
		free(arr);
		arr++;
	}
	free_2d(data->map);
	return (false);
}

void	error_close_window(t_imgdata *data, char *str)
{
	ft_putendl_fd("Error\n", STDOUT_FILENO);
	ft_putendl_fd(str, STDOUT_FILENO);
	terminate(data);
}

void	free_close_window(t_imgdata *data, void *var, char *str)
{
	ft_putendl_fd("Error\n", STDOUT_FILENO);
	ft_putendl_fd(str, STDOUT_FILENO);
	free(var);
	terminate(data);
}

size_t	getncount(char *str, uint8_t chr)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == chr)
			count++;
		str++;
	}
	return (count);
}
