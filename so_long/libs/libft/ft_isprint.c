/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:17:57 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/19 14:17:58 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int arg)
{
	if (arg >= ' ' && arg <= '~')
	{
		return (1);
	}
	return (0);
}

/*#include	<stdio.h>
int main(void)
{
	int x;

	x = ft_isprint("f");
	printf ("%d", x);
	return (0);
}*/