# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 11:58:13 by iecer             #+#    #+#              #
#    Updated: 2024/05/20 12:47:44 by iecer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC				=	sourcefile/map_control.c	\
					sourcefile/exit.c	\
					sourcefile/map_create.c	\
					sourcefile/main.c	\
					sourcefile/data_create.c	\
					sourcefile/map_played_control.c

LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH 	=	minilibx
MLX				= 	minilibx/libmlx.a
OBJ				=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(MLX) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX):
	make -C $(MINILIBX_PATH) all

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:	all clean fclean re libft
