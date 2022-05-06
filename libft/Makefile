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
SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
				ft_memcmp.c ft_strlen.c  ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
				ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

BONUS		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				
OBJS		= $(SRCS: .c=.o)

BONUS_OBJS	= $(BONUS: .c=.o)

NAME		= libft.a

FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) -c $(BO)

$(NAME):
	$(OBJS)
	ar -rc $(NAME) $(OBJS)

bonus:
	$(OBJS) $(BONUS_OBJS)
	ar -rc $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY:	all clean fclean re bonus