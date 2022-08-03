/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:15:05 by jperez-p          #+#    #+#             */
/*   Updated: 2022/06/29 15:53:21 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pacomprueba(char c, va_list lista, int maletin)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(lista, int), 1);
		maletin++;
	}
	else if (c == 's')
		maletin = ft_putstr_fd(va_arg(lista, char *), maletin, 1);
	else if (c == 'p')
		maletin = lap(va_arg(lista, unsigned long), maletin, 1);
	else if (c == 'i' || c == 'd')
		maletin = ft_putnbr_fd(va_arg(lista, int), maletin, 1);
	else if (c == 'u')
		maletin = lau(va_arg(lista, unsigned int), maletin);
	else if (c == 'x')
		maletin = lax(va_arg(lista, unsigned int), maletin);
	else if (c == 'X')
		maletin = laxmayus(va_arg(lista, unsigned int), maletin);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		maletin++;
	}
	return (maletin);
}

int	ft_printf(char const *p, ...)
{
	va_list	parametros;
	int		count;
	int		maletin;

	count = 0;
	maletin = 0;
	va_start(parametros, p);
	while (p[count])
	{
		if (p[count] == '%')
		{
			if (ft_strchr("cspdiuxX%", p[count +1]))
				maletin = pacomprueba(p[count++ +1], parametros, maletin);
		}
		else
		{
			ft_putchar_fd(p[count], 1);
			maletin++;
		}
		count++;
	}
	va_end(parametros);
	return (maletin);
}
