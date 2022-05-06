/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:14:07 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/19 13:46:56 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int arg)
{
	if ((arg >= 'a' && arg <= 'z')
		|| (arg >= 'A' && arg <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/*#include	<stdio.h>
int main(void)
{
	int x;

	x = ft_isalpha('w');
	printf ("%d", x);
	return (0);
}*/