/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:38:42 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/15 13:22:30 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int32_t argc, char **argv)
{
	t_imgdata		data;
	int32_t			fd;

	ft_bzero(&data, sizeof(t_imgdata));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (ft_putendl_fd("Error\nInvalid file", STDOUT_FILENO) \
					, EXIT_FAILURE);
		if (!check_ext(argv[1], ".ber"))
			return (EXIT_FAILURE);
		if (!(input_handler(fd, &data, &data.line)))
			return (EXIT_FAILURE);
	}
	else if (argc > 2)
		return (ft_putendl_fd("Error\nToo many arguments dude", \
				STDOUT_FILENO), EXIT_FAILURE);
	else
		return (ft_putendl_fd("Error\nNot enough arguments dude", \
				STDOUT_FILENO), EXIT_FAILURE);
	if (!graphics(&data, &data.line))
		free_2d(data.map);
	return (0);
}
