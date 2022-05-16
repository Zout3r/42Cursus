/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:40:48 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/19 14:40:49 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int arg)
{
	if (arg >= 0 && arg <= 127)
	{
		return (1);
	}
	return (0);
}

/*#include	<stdio.h>
int main(void)
{
	int x;

	x = ft_isascii("é");
	printf ("%d", x);
	return (0);
}*/