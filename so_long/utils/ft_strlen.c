/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:44:48 by jperez-p          #+#    #+#             */
/*   Updated: 2022/07/25 14:36:27 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *arg)
{
	int	count;

	count = 0;
	while (arg[count] != '\0')
	{
		count++;
	}
	return (count);
}

/*#include <stdio.h>

int main()
{
    char *str = "hola";
    printf("\"%s\" : %d\n", str, ft_strlen(str));
}*/