# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_windows.mk                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 19:07:41 by jperez-p          #+#    #+#              #
#    Updated: 2022/08/09 19:07:49 by jperez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBM_STATE 	:= $(shell dir "libs\libft")
CC			:= gcc

SRCS		:= $(wildcard $(SRCDIR)*.c) \
			   $(wildcard $(SRCDIR)*/*.c)
#			   $(wildcard $(LIBFT)*.c)

BONUS		:= $(wildcard $(BONUSDIR)*.c) \
			  $(filter-out $(wildcard $(UNIXDIR)*.c), $(wildcard $(BONUSDIR)*/*.c)) 

SRCS		:= $(subst /,\,$(SRCS))
BONUS		:= $(subst /,\,$(BONUS))
LIBFT		:= $(subst /,\,$(LIBFT))
LIBMLX		:= $(subst /,\,$(LIBMLX))
HEADERS		:= $(subst /,\,$(HEADERS))
BONUS		:= $(subst /,\,$(BONUS))
	
LIBS		:= -lglfw3 -lopengl32 -lgdi32

NL			:= 
NC			:= [0m
RED 		:= [91m
GREEN 		:= [92m
BLUE 		:= [96m
PURPLE		:= [95m
