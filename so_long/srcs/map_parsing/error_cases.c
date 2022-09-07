/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:46:49 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/15 13:20:42 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_output(t_error *errors, t_line *line)
{
	if (errors->no_cpe == true || errors->different_input == true \
		|| errors->file_name == true || errors->not_rectangular == true \
		|| errors->walls == true || errors->morecharacters == true \
		|| line->count == 0)
	{
		errors->error = true;
		ft_putendl_fd("Error", STDOUT_FILENO);
	}
	if (errors->no_cpe == true)
		ft_putendl_fd("Does not contain at least 1 collectible, \
		map exit and starting position", STDOUT_FILENO);
	if (errors->different_input == true)
		ft_putendl_fd("Contains input other than 01CEP", STDOUT_FILENO);
	if (errors->not_rectangular == true)
		ft_putendl_fd("Map is not not_rectangular", STDOUT_FILENO);
	if (errors->walls == true)
		ft_putendl_fd("Map is not surrounded by walls", STDOUT_FILENO);
	if (errors->morecharacters == true)
		ft_putendl_fd("Map contains too many characters", STDOUT_FILENO);
}
