/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:09:10 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/21 12:09:11 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char	*str, int c)
{
	int	count;

	count = ft_strlen((char *)str) + 1;
	while (count--)
	{
		if (*(str + count) == c)
		{
			return ((char *)(str + count));
		}
	}
	return (0);
}

/*int main () {
   char str[] = "http://www.estoesunaprueba.com";
   char ch = '.';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after last |%c| is %s\n", ch, ret);
   
   return(0);
}*/