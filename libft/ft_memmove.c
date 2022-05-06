/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:45:23 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 14:45:24 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void	*str1, const void	*str2, size_t n)
{
	size_t		count;

	count = 0;
	if (str1 == str2 || !n)
		return (str1);
	if (str1 < str2)
	{
		while (count < n)
		{
			*((char *)str1 + count) = *((char *)str2 + count);
			count++;
		}
	}
	else
	{
		while (n > 0)
		{
			*((char *)str1 + n - 1) = *((char *)str2 + n - 1);
			n--;
		}
	}
	return (str1);
}

/*#include <stdio.h>
#include <string.h>

int main () {
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   printf("Before ft_memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 9);
   printf("After ft_memmove dest = %s, src = %s\n", dest, src);

   return(0);
}*/