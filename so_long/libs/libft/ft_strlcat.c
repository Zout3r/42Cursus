/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:25:46 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 15:25:47 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	src_count;
	size_t	value;

	count = 0;
	src_count = 0;
	value = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dest))
		value = ft_strlen(src) + size;
	else
		value = ft_strlen(src) + ft_strlen(dest);
	while (dest[count] != '\0')
	{
		count++;
	}
	while (src[src_count] != '\0' && count + 1 < size)
	{
		dest[count] = src[src_count];
		src_count++;
		count++;
	}
	dest[count] = '\0';
	return (value);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[] = "hola";
	char b[] = "mundo";
	unsigned int x = ft_strlcat(a, b, 6);
	printf("%s %d", a, x);
}*/