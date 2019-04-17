# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 15:02:28 by nalexand          #+#    #+#              #
#    Updated: 2019/04/17 09:23:10 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

SOURCES =	ft_atoi.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strnew.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_strsplit.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strlen.c \
			ft_strjoin.c \
			ft_strdup.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_memchr.c \
			ft_strlcat.c \
			ft_memset.c \
			ft_memmove.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memcmp.c \
			ft_bzero.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstclear.c \
			ft_numlen.c \
			ft_strclen.c \
			ft_wrdcount.c \
			ft_strcskp.c \
			ft_strsskp.c

OBJECTS = $(SOURCES:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $@ $(OBJECTS)

$(OBJECTS): $(SOURCES)
	gcc $(CFLAGS) $(SOURCES)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
