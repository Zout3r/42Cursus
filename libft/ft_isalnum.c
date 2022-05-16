/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:07:54 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/19 14:07:55 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int arg)
{
	if ((arg >= 'a' && arg <= 'z')
		|| (arg >= 'A' && arg <= 'Z')
		|| (arg >= '0' && arg <= '9'))
	{
		return (1);
	}
	return (0);
}

/*#include	<stdio.h>
int main(void)
{
	int x;

	x = ft_isalnum("er3A");
	printf ("%d", x);
	return (0);
}*/