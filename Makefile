# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 16:05:38 by vcaquant          #+#    #+#              #
#    Updated: 2016/11/20 17:31:55 by vcaquant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			wolf3d

SRC = 			sources/fractol.c \
				sources/ft_recup.c \
				sources/init.c \
				sources/ft_code.c \
				sources/drawline.c \
				sources/drawline_beeline.c \
				sources/drawline_cadran.c \
				sources/drawline_cadran2.c \
				sources/draw_line.c \
				sources/ft_error.c \
				sources/minimap.c \
				sources/put.c \
				sources/ft_balader.c

OBJ = 			fractol.o \
				ft_recup.o \
				init.o \
				ft_code.o \
				drawline.o \
				drawline_beeline.o \
				drawline_cadran.o \
				drawline_cadran2.o \
				draw_line.o \
				ft_error.o \
				minimap.o \
				put.o \
				ft_balader.o

HEADER =		./libft/libft.h

FINDLIBFT =		-Llibft

PT_A =			./minilibx_macos/libmlx.a \
			./libft/libft.a

FLAGS = 		-Wall -Wextra -Werror -g

LIBX_FS =		-framework OpenGL -framework AppKit

LIBFT_DIR =		./libft/

LIBX_DIR =		./minilibx_macos/

CC = 			gcc

all:	comp_oth $(NAME)

comp_oth:
		@make fclean -C $(LIBFT_DIR)
		@make -C $(LIBFT_DIR)
		@make -C $(LIBX_DIR)

$(NAME):
		@clear
		@$(CC) $(FLAGS) -c $(SRC) $(HEADER)
		@$(CC) -o $(NAME) $(OBJ) $(PT_A) $(LIBX_FS)
		@echo "\033[0;32m✔︎ Compilation Done\033[0m"

clean:
		@clear
		@rm -f $(OBJ)
		@rm -f fdf.h.gch
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(LIBX_DIR)
		@echo "\033[0;31m✔︎ Cleaning Done\033[0m"

fclean:	clean
		@clear
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR)
		@echo "\033[0;31m✔︎ Fcleaning Done\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
