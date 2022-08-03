/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:29:43 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/03 16:12:55 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	count;
	char			*des;

	count = 0;
	des = malloc(len + 1);
	if (!des)
		return (NULL);
	while (start < ft_strlen(s) && s[count + start] != '\0' && count < len)
	{
		des[count] = s[count + start];
		count++;
	}
	des[count] = '\0';
	return (des);
}
