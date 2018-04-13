# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/10 17:53:36 by agregoir          #+#    #+#              #
#    Updated: 2017/11/30 18:44:32 by agregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
OBJ = $(PRE_SRC_LIBFT:.c=.o)
INC = -I ./sources

PRE_SRC_CONV = ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c
PRE_SRC_PRINTF = arg_check_and_itoa.c call_and_format.c check_errors_flags.c conversions_1.c \
conversions_2.c conversions_3.c conversions_4.c format.c format_flag.c ft_printf.c \
functions_zero.c is_flag.c parsing.c precision.c
PRE_SRC_IS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
PRE_SRC_LIST = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c
PRE_SRC_MEM = ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c
PRE_SRC_PUT = ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
PRE_SRC_STR = ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strjoin_free.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c
PRE_SRC_MATH = ft_power.c

PRE_SRC_LIBFT = $(PRE_SRC_CONV) $(PRE_SRC_PRINTF) $(PRE_SRC_IS) \
$(PRE_SRC_LIST) $(PRE_SRC_MEM) $(PRE_SRC_PUT) $(PRE_SRC_STR) \
$(PRE_SRC_MATH) ./get_next_line.c

SRC_CONV = $(addprefix ./sources/conv/, $(PRE_SRC_CONV))
SRC_PRINTF = $(addprefix ./sources/ft_printf/, $(PRE_SRC_PRINTF))
SRC_IS = $(addprefix ./sources/is/, $(PRE_SRC_IS))
SRC_LIST = $(addprefix ./sources/list/, $(PRE_SRC_LIST))
SRC_MEM = $(addprefix ./sources/mem/, $(PRE_SRC_MEM))
SRC_PUT = $(addprefix ./sources/put/, $(PRE_SRC_PUT))
SRC_STR = $(addprefix ./sources/str/, $(PRE_SRC_STR))
SRC_MATH = $(addprefix ./sources/math/, $(PRE_SRC_MATH))

SRC_LIBFT = $(SRC_CONV) $(SRC_PRINTF) $(SRC_IS) \
$(SRC_LIST) $(SRC_MEM) $(SRC_PUT) $(SRC_STR) $(SRC_MATH) \
./sources/get_next_line.c


all: $(NAME)

$(NAME): $(SRC_PRINTF)
	@gcc $(FLAG) -c $(INC) $(SRC_LIBFT)
	@ar -rc $(NAME) $(OBJ) $(LIB)
	@echo "\033[32m[✓] \033[33m libft.a was created successfully\033[0m"
	@mkdir -p ./sources/obj
	@mv $(OBJ) ./sources/obj

clean:
	@rm -rf ./sources/obj

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[32m[✓] \033[33m libft.a was destroyed\033[0m"

re: fclean all
