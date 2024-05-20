# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 18:45:47 by beeren            #+#    #+#              #
#    Updated: 2024/04/17 14:47:24 by iecer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_striteri.c\
ft_memcpy.c \
ft_memset.c \
ft_itoa.c \
ft_strmapi.c \
ft_strchr.c \
ft_strlcpy.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strdup.c \
ft_calloc.c \
ft_putnbr_fd.c \
ft_memmove.c \
ft_strlen.c \
ft_strncmp.c \
ft_substr.c \
ft_putendl_fd.c \
ft_strnstr.c \
ft_strrchr.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_tolower.c \
ft_toupper.c \
ft_strlcat.c \
ft_split.c \
ft_printf.c \
ft_puthex.c \
ft_putnbr.c \
ft_putptr.c \
ft_putstrchr.c \

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
