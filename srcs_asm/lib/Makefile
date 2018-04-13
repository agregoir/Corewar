# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:42:55 by fel-mazo          #+#    #+#              #
#    Updated: 2017/11/08 14:25:57 by fel-mazo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
SRCDIR	= srcs
SRC		= ft_atoi.c ft_bzero.c ft_echocharptr.c ft_echoint.c \
		 ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		 ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c \
		 ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		 ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c \
		 ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		 ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
		 ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
		 ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c\
		 ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
		 ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
		 ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c\
		 ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
		 ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
		 ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
		 ft_strtrimwhites.c ft_tolower.c ft_toupper.c \
		 ft_lstlen.c ft_printlst.c ft_strchri.c ft_memchri.c\
		 ft_memrealloc.c ft_memcpy.c ft_bzero.c ft_memset.c ft_strlen.c \
		 do_jobs.c pf_init.c ft_printf.c parse.c pf_s.c pf_di.c wutils.c \
		 utils1.c utils2.c utils3.c utils4.c utils5.c ft_strchr.c \
		 ft_isdigit.c ft_memchr.c get_next_line.c ft_exit.c ft_malloc.c

OBJ		= $(SRC:.c=.o)

.PHONY: build clean fclean re

all : $(NAME)

%.o : $(SRCDIR)/%.c
	@echo "" | $(CC) $(CFLAGS) -c -g -I ./includes $^

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)
