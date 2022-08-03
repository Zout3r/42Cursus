# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 15:44:25 by jperez-p          #+#    #+#              #
#    Updated: 2022/08/03 16:25:17 by jperez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	=	./utils/ft_strjoin.c					\
			./utils/ft_itoa.c						\
			./utils/get_map.c						\
			./utils/ft_split.c						\
			./utils/put_image.c						\
			./utils/put_text.c						\
			./get_next_line/get_next_line_utils.c	\
			./get_next_line/get_next_line.c			\
			./utils/check_file.c					\
			./utils/check_map_paco.c				\
			./utils/check_map.c						\
			./utils/animation.c						\
			./utils/animation_paco.c				\
			./utils/exit_door.c						\
			main.c									\
			./utils/movement.c						\
			./ft_printf/ft_printf.c					\
			./ft_printf/ojalamorirme.c 				\
			./ft_printf/ft_strchr.c 				\
			./ft_printf/ft_putstr_fd.c 				\
			./ft_printf/ft_putnbr_fd.c 				\
			./ft_printf/ft_putchar_fd.c 			\


all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) MLX42/libmlx42.a -I include -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/" $^ -o $@
	@echo "\[\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all