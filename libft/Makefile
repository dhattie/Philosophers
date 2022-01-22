# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhattie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 21:41:13 by dhattie           #+#    #+#              #
#    Updated: 2021/05/03 21:41:16 by dhattie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a
SRC =   ft_bzero.c      ft_memccpy.c    ft_memcpy.c     ft_memmove.c\
        ft_memset.c     ft_tolower.c    ft_toupper.c    ft_isprint.c\
        ft_isascii.c    ft_isalnum.c    ft_isdigit.c    ft_isalpha.c\
        ft_atoi.c       ft_strncmp.c    ft_strlen.c     ft_memchr.c\
        ft_memcmp.c     ft_strchr.c     ft_strrchr.c    ft_calloc.c\
        ft_strdup.c     ft_strlcpy.c    ft_strlcat.c    ft_strnstr.c\
        ft_substr.c     ft_strjoin.c    ft_strtrim.c    ft_split.c\
        ft_itoa.c       ft_strmapi.c    ft_putchar_fd.c ft_putstr_fd.c\
        ft_putendl_fd.c ft_putnbr_fd.c	get_next_line.c

OBJ = $(patsubst %.c,%.o,$(SRC))

FLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME) : $(OBJ)
	ar rcs $(NAME) $?
%.o : %.c libft.h
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
test:$(NAME)
	gcc $(FLAGS) -L. -lft main.c -o test && ./test
.PHONY : all clean fclean re test
