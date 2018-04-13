# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:42:55 by fel-mazo          #+#    #+#              #
#    Updated: 2018/04/07 17:02:44 by icampill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAMEX	= asm
CFLAGS	= -Wall -Wextra -Werror
SRCDIR	= srcs
SRC		= check.c debug.c ins.c main.c meta.c params.c token.c utils1.c\
			utils2.c write.c cleanup.c
OBJ		= $(SRC:.c=.o)

.PHONY: build clean fclean re $(NAMEX)

all : $(NAMEX)

%.o : $(SRCDIR)/%.c
	@echo "." | $(CC) $(CFLAGS) -c -I ./includes $^

$(NAMEX) : $(OBJ)
	@make -C ./lib
	@$(CC) $(CFLAGS) -I./includes -L./lib -lft $(OBJ) -o $(NAMEX)
	@echo "\033[32m[✓] \033[33m asm was created successfully\033[0m"
	@mkdir -p ./obj
	@mv $(OBJ) ./obj

clean :
	@rm -rf ./obj
	@make -C lib/ clean
	@echo "\033[32m[✓] \033[33m all the asm object files were destroyed\033[0m"

fclean : clean
	@rm -f $(NAMEX)
	@make -C lib/ fclean
	@echo "\033[32m[✓] \033[33m asm was destroyed\033[0m"

re : fclean $(NAMEX)
