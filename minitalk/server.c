/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:41:42 by jperez-p          #+#    #+#             */
/*   Updated: 2022/09/20 15:44:03 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal)
{
	static char	c = 0;
	static int	pos = 0;
	int			bit;

	if (signal == SIGUSR1)
		bit = 0;
	else if (signal == SIGUSR2)
		bit = 1;
	else
		exit(EXIT_FAILURE);
	c += bit << pos++;
	if (pos == 7)
	{
		if (!c)
			c = '\n';
		ft_putchar(c);
		c = 0;
		pos = 0;
	}
}

int	main(void)
{
	ft_putstr("Server running: PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (42)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
