/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:00:14 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/21 17:00:15 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *find, size_t len)
{
	size_t		count;

	if (*find == '\0')
	{
		return ((char *)big);
	}
	count = ft_strlen((char *)find);
	while (*big != '\0' && len-- >= count)
	{
		if (*big == *find && ft_memcmp(big, find, count) == 0)
		{
			return ((char *)big);
		}
		big++;
	}
	return (NULL);
}

/*
int main () {
   char *str = "http://www.thisisatest.com";
   char *ch = "w";
   char *ret;

   ret = ft_strnstr(str, ch, 15);

   printf("String after |%s| is %s\n", ch, ret);

   return(0);
}*/