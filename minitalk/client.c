/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:41:51 by jperez-p          #+#    #+#             */
/*   Updated: 2022/09/20 15:45:17 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define DELAY 69

static void	send_msg(int pid, char *str)
{
	int	pos;
	int	len;
	int	i;

	len = ft_strlen(str);
	i = -1;
	while (++i <= len)
	{
		pos = -1;
		while (++pos < 7)
		{
			if ((str[i] >> pos) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(DELAY);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr("Usage: client <PID> <string>\n");
		exit(EXIT_FAILURE);
	}
	send_msg(ft_atoi(av[1]), av[2]);
}
