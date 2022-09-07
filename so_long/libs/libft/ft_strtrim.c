/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:55:49 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/28 16:55:50 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	size;

	if (s1 == 0 || set == 0)
	{
		return (NULL);
	}
	while (ft_strchr(set, *s1) && *s1 != '\0')
	{
		s1++;
	}
	size = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[size]) && size != '\0')
	{
		size--;
	}
	return (ft_substr((char *)s1, 0, size + 1));
}
