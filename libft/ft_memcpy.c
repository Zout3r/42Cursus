/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:43:35 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 14:24:12 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	char				*d;
	const char			*s;
	size_t				count;

	d = dest;
	s = src;
	count = 0;
	if (d == s || !n)
		return (dest);
	while (count < n)
	{
		d[count] = s[count];
		count++;
	}
	return (dest);
}

/*
#include <string.h>

int main () {
   const char src[50] = "Hastupatapotapitahija";
   char dest[50];
   strcpy(dest,"Hemlo!!");
   printf("Before ft_memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src)+1);
   printf("After ft_memcpy dest = %s\n", dest);
   
   return(0);
}*/