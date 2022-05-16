/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:35:18 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/26 14:58:27 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
	{
		return (0);
	}
	while (count < n)
	{
		if (str1[count] && str1[count] == str2[count])
		{
			while (str1[count] && str1[count] == str2[count] && count < n)
			{
				count++;
			}
		}
		else
		{
			return ((unsigned char)str1[count] - (unsigned char)str2[count]);
		}
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];
   int ret;

   strcpy(str1, "\200");
   strcpy(str2, "\0");

   ret = ft_strncmp(str1, str2, 3);

   if(ret < 0) 
   {
      printf("str1 is less than str2");
   } 
   else if(ret > 0) 
   {
      printf("str2 is less than str1");
   } 
   else 
   {
      printf("str1 is equal to str2");
   }
   
   return(0);
}*/
