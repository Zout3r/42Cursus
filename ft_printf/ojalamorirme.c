/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ojalamorirme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:24 by jperez-p          #+#    #+#             */
/*   Updated: 2022/06/27 15:21:22 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lau(unsigned int laputa, int maletin)
{
	char	*base;

	base = "0123456789";
	if (laputa >= 10)
	{
		maletin = lau(laputa / 10, maletin);
		maletin = lau(laputa % 10, maletin);
	}
	else
	{
		ft_putchar_fd(base[laputa], 1);
		maletin++;
	}
	return (maletin);
}

int	lax(unsigned int laputa, int maletin)
{
	char	*base;

	base = "0123456789abcdef";
	if (laputa >= 16)
	{
		maletin = lax(laputa / 16, maletin);
		maletin = lax(laputa % 16, maletin);
	}
	else
	{
		ft_putchar_fd(base[laputa], 1);
		maletin++;
	}
	return (maletin);
}

int	laxmayus(unsigned int laputa, int maletin)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (laputa >= 16)
	{
		maletin = laxmayus(laputa / 16, maletin);
		maletin = laxmayus(laputa % 16, maletin);
	}
	else
	{
		ft_putchar_fd(base[laputa], 1);
		maletin++;
	}
	return (maletin);
}

int	lap(unsigned long laputa, int maletin, int bolo)
{
	char	*base;

	base = "0123456789abcdef";
	if (bolo)
	{
		write(1, "0x", 2);
		maletin += 2;
	}
	if (laputa >= 16)
	{
		maletin = lap(laputa / 16, maletin, 0);
		maletin = lap(laputa % 16, maletin, 0);
	}
	else
	{
		ft_putchar_fd(base[laputa], 1);
		maletin++;
	}
	return (maletin);
}
