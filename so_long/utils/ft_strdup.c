/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:05:18 by jperez-p          #+#    #+#             */
/*   Updated: 2022/07/25 14:19:12 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*des;

	count = 0;
	des = malloc(ft_strlen(s1) + 1);
	if (des == 0)
	{
		return (NULL);
	}
	while (s1[count])
	{
		des[count] = s1[count];
		count++;
	}
	des[count] = '\0';
	return (des);
}
