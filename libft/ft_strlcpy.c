/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:54:02 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 14:54:03 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	cont;
	size_t	cont2;

	cont2 = 0;
	cont = 0;
	while (src[cont2])
	{
		cont2++;
	}
	while (src[cont] && cont + 1 < size)
	{
		dest[cont] = src[cont];
		cont++;
	}
	if (size)
		dest[cont] = '\0';
	return (cont2);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
   char var1[] = "stuff";
   char var2[] = "world!";
   ft_strlcpy(var1, var2, sizeof(var2));
   printf("hello %s", var1);
}*/