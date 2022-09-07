# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_unix.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 19:07:28 by jperez-p          #+#    #+#              #
#    Updated: 2022/08/09 19:17:51 by jperez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS 		:= $(shell uname -s)
ARCH 	:= $(shell uname -m)
SUBM_STATE := $(shell find libs/libft -type f)
DEBUG 		:= -fsanitize=address

BONUS 	:= ./libs/libft/*.c \
		  ./bonus/enemy/damage.c \
		  ./bonus/enemy/init.c \
		  ./bonus/enemy/interaction.c \
		  ./bonus/enemy/spawn.c \
		  ./bonus/graphics/animation.c \
		  ./bonus/graphics/display.c \
		  ./bonus/graphics/end.c \
		  ./bonus/graphics/graphics.c \
		  ./bonus/graphics/images_to_window.c \
		  ./bonus/graphics/loading_images.c \
		  ./bonus/map_parsing/check_player_amount.c \
		  ./bonus/map_parsing/error_cases.c  \
  		  ./bonus/map_parsing/input_handler.c \
		  ./bonus/map_parsing/read_map.c \
		  ./bonus/map_parsing/obstacle.c \
		  ./bonus/player/gravity_jump.c \
		  ./bonus/player/movement.c \
		  ./bonus/utils.c \
		  ./bonus/main.c \
		  ./bonus/collectible.c \
		  ./bonus/unix/audio.c \
		  ./bonus/unix/process_functions.c

SRCS	:= ./libs/libft/*.c \
		  ./srcs/graphics/end.c \
		  ./srcs/graphics/graphics.c \
		  ./srcs/graphics/images_to_window.c \
		  ./srcs/graphics/loading_images.c \
		  ./srcs/map_parsing/check_player_amount.c \
		  ./srcs/map_parsing/error_cases.c  \
  		  ./srcs/map_parsing/input_handler.c \
		  ./srcs/map_parsing/read_map.c \
		  ./srcs/map_parsing/obstacle.c \
		  ./srcs/player/gravity_jump.c \
		  ./srcs/player/movement.c \
		  ./srcs/utils.c \
		  ./srcs/main.c \
		  ./srcs/collectible.c

NL		:= \n
Q		:= "
NC		:= \033[0m
RED 	:= \033[1;31m
GREEN 	:= \033[1;32m
BLUE 	:= \033[1;34m
PURPLE	:= \033[35;1m

# determining architecture for the Mac
ifeq ($(ARCH), x86_64)
GLFW 	:= libs/MLX42/libmlx42.a
else ifeq ($(ARCH), arm)
GLFW 	:= libs/MLX42/libmlx42.a
else 
GLFW 	:= libs/MLX42/libmlx42.a
endif

# for cross-platform compatibility
ifeq ($(OS), Darwin)
LIBS	:= -framework Cocoa -framework OpenGL, -framework IOKit $(GLFW)
else ifeq ($(OS), Linux)
LIBS	:= -ldl -lglfw
endif
