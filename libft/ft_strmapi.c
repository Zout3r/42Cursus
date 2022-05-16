/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:13:35 by jperez-p          #+#    #+#             */
/*   Updated: 2022/05/03 16:13:36 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	count;
	char	*tmp;

	count = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!s || !f || !tmp)
		return (NULL);
	while (count < (ft_strlen((char *)s)))
	{
		tmp[count] = f(count, s[count]);
		count++;
	}
	tmp[count] = '\0';
	return (tmp);
}
