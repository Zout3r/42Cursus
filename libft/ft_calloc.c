/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:56:43 by jperez-p          #+#    #+#             */
/*   Updated: 2022/04/27 13:56:44 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*buffer;

	buffer = malloc(size * nitems);
	if (buffer == 0)
	{
		return (NULL);
	}
	ft_bzero(buffer, size * nitems);
	return (buffer);
}
