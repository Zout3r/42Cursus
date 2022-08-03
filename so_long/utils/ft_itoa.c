/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:23:19 by jperez-p          #+#    #+#             */
/*   Updated: 2022/07/25 15:46:01 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_paco(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*value;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_paco(n);
	value = (char *)ft_calloc(len + 1, sizeof(char));
	if (!(value))
		return (NULL);
	if (n < 0)
	{
		value[0] = '-';
		n = -n;
	}
	value[len] = '\0';
	len--;
	while (n != 0)
	{
		value[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (value);
}
