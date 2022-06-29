/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:32:25 by jperez-p          #+#    #+#             */
/*   Updated: 2022/06/27 15:19:11 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

# define BUFFER_SIZE 1

char				*ft_strchr(const char *str, int c);
void				ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int maletin, int fd);
int					ft_putnbr_fd(int n, int maletin, int fd);
int					ft_printf(char const *p, ...);
int					lau(unsigned int laputa, int maletin);
int					lax(unsigned int laputa, int maletin);
int					laxmayus(unsigned int laputa, int maletin);
int					lap(unsigned long laputa, int maletin, int bolo);

#endif