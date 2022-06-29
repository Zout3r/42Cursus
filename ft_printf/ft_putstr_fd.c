/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:17:29 by jperez-p          #+#    #+#             */
/*   Updated: 2022/06/27 15:25:18 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int maletin, int fd)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (maletin += 6);
	}
	while (s[count])
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
	maletin += count;
	return (maletin);
}
