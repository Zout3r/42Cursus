# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 13:41:27 by jperez-p          #+#    #+#              #
#    Updated: 2022/04/25 13:41:28 by jperez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libftprintf.a

SRCS		= 	ft_putchar_fd.c \
				ft_strchr.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_printf.c \
				ojalamorirme.c \
                
OBJS        = $(SRCS:%.c=%.o)



FLAGS       = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
    
re: fclean all

.PHONY: all clean fclean re