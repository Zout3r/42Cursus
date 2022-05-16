/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:45:55 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 15:45:56 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char	*str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main () {
   char str[] = "http://www.estoesunaprueba.com";
   char ch = '.';
   char *ret;

   ret = ft_strchr(str, ch);

   printf("String after |%c| is %s\n", ch, ret);
   
   return(0);
}*/