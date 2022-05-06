/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:41:30 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/21 14:41:31 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		if (*((unsigned char *)str + count) == (unsigned char)c)
		{
			return ((void *)str + count);
		}
		count++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main () {
   char str[] = "http://www.thisisatest.com";
   char ch = '.';
   char *ret;

   ret = ft_memchr(str, ch, sizeof(str));

   printf("String after |%c| is %s\n", ch, ret);

   return(0);
}*/