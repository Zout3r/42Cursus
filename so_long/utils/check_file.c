/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:45:07 by jperez-p          #+#    #+#             */
/*   Updated: 2022/07/25 14:18:37 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	find(char *str, char *to_find)
{
	int	count;

	count = 0;
	while (to_find[count])
	{
		if (to_find[count] != str[count])
			return (0);
		count++;
	}
	if (str[count] == 0)
		return (1);
	return (0);
}

void	check_file(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (find(file_line, ".ber"))
			{
				return ;
			}
		}
		file_line++;
	}
	ft_printf("Error: El archivo no es válido");
	exit(1);
}