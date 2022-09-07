/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_amount.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:47:05 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/15 13:22:19 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_amount(t_error *errors, t_imgdata *data)
{
	char	*foundchar;

	foundchar = ft_strchr(data->bigass, 'P');
	if (foundchar)
	{
		if (ft_strchr(foundchar + 1, 'P'))
			errors->morecharacters = true;
	}
}
