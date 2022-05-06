/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:07:59 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/27 17:08:01 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_paco2(char *value, const char *s1, const char *s2)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (s1[count] != '\0')
	{
		value[count2] = s1[count];
		count++;
		count2++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		value[count2] = s2[count];
		count++;
		count2++;
	}
	value[count2] = '\0';
	return (value);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*value;

	value = malloc(ft_strlen(s1) + ft_strlen(s2));
	if (value == 0 || s1 == 0 || s2 == 0)
	{
		return (NULL);
	}
	ft_paco2(value, s1, s2);
	return (value);
}
