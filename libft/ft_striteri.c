/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:29:07 by jperez-p          #+#    #+#             */
/*   Updated: 2022/05/04 13:29:08 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	var;
	int	var2;

	var = 0;
	var2 = 0;
	if (s != NULL && f != NULL)
	{
		var = ft_strlen(s);
		while (var2 < var)
		{
			(*f)(var2, s);
			s++;
			var2++;
		}
	}
}
