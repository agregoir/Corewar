# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/10 17:53:36 by agregoir          #+#    #+#              #
#    Updated: 2018/03/07 19:23:25 by agregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= corewar
FLAG 	= -Wall -Wextra -Werror
SRC_DIR	= srcs
SRC 	= acquire_champ.c init.c main.c parse.c tool.c wage_war.c ocp.c \
manage_proc.c load.c op_tool.c op_tool_2.c op_1.c op_2.c op_3.c op_4.c \
curses_visu.c curses_visu_print.c curses_visu_breakdown.c manage_op.c
OBJ		= $(SRC:.c=.o)
LIB 	= libft/libft.a
INC		= -I ./libft/sources/ -I ./libft/sources/ft_printf -I ./includes

.PHONY: build clean fclean re $(NAME)

all : $(NAME)

%.o : $(SRC_DIR)/%.c
	@echo "." | $(CC) $(FLAG) -c $(INC) $^

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) -lncurses $(FLAG) $(INC) $(LIB) $(OBJ) -o $(NAME)
	@echo "\033[32m[✓] \033[33m corewar was created successfully\033[0m"
	@mkdir -p ./obj
	@mv $(OBJ) ./obj

clean :
	@rm -rf ./obj
	@make -C libft/ clean
	@echo "\033[32m[✓] \033[33m all the corewar object files were destroyed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[32m[✓] \033[33m corewar was destroyed\033[0m"

re : fclean $(NAME)
