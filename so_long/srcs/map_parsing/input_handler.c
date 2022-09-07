/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:46:32 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/15 13:21:04 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_ext(char *file_name, char *ext)
{
	size_t	ext_len;
	size_t	name_len;

	if (!ext)
		return (ft_putendl_fd("Error\nYou are not checking for an extension", \
				STDOUT_FILENO), false);
	if (!file_name)
		return (ft_putendl_fd("Error\nThere is no file name", \
				STDOUT_FILENO), false);
	ext_len = ft_strlen(ext);
	name_len = ft_strlen(file_name);
	while (ext_len > 0)
	{
		if (file_name[name_len--] != ext[ext_len--])
			return (ft_putendl_fd("Error\nWrong file extension", \
					STDOUT_FILENO), false);
	}
	return (true);
}

static bool	check_walls(char **map, t_line *line, \
						t_error *errors)
{
	ssize_t	i;

	i = 0;
	ft_strchr(map[line->count], '1');
	while (i < line->size)
	{
		if (map[0][i] != '1' || map[line->count][i++] != '1')
			return (errors->walls = true, false);
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][line->size - 1] != '1')
			return (errors->walls = true, false);
		i++;
	}
	return (true);
}

static bool	check_cases(t_error *errors, t_imgdata *data)
{
	size_t	i;

	i = 0;
	check_player_amount(errors, data);
	if (!(ft_strchr(data->bigass, 'C')) || !(ft_strchr(data->bigass, 'P')) \
	|| !(ft_strchr(data->bigass, 'E')))
		errors->no_cpe = true;
	while (data->bigass[i])
	{
		if (data->bigass[i] == 'C')
			data->pickup_max++;
		if (!(ft_strchr("01CEP\n", data->bigass[i++])))
			errors->different_input = true;
	}
	if (errors->no_cpe == true || errors->different_input == true)
		return (false);
	return (true);
}

static size_t	check_if_not_rectangular(char **map, t_line *line, \
									t_error *errors)
{
	ssize_t	i;

	i = 0;
	while (map[i + 1])
	{
		line->size = ft_strlen(map[i++]);
		if (line->size != (ssize_t)ft_strlen(map[i]))
			errors->not_rectangular = true;
	}
	line->count = ft_strlen(map[i]);
	if (line->size == i)
		errors->not_rectangular = true;
	return (i);
}

char	**input_handler(int32_t fd, t_imgdata *data, t_line *line)
{
	t_error	errors;

	ft_bzero(&errors, sizeof(t_error));
	data->bigass = read_file(fd);
	if (!(*data->bigass))
		return (ft_putendl_fd("Error\nEmpty map", STDOUT_FILENO), NULL);
	data->map = ft_split(((const char *)data->bigass), '\n');
	if (!data->map)
		return (ft_putendl_fd("Error\nInvalid map", STDOUT_FILENO), NULL);
	line->count = check_if_not_rectangular(data->map, line, &errors);
	check_cases(&errors, data);
	check_walls(data->map, line, &errors);
	error_output(&errors, line);
	if (errors.error == true)
		return (free_2d(data->map), NULL);
	return (data->map);
}
