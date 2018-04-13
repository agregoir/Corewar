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

NAME = do_it

.PHONY: build clean fclean re $(NAMEX)

all : $(NAME)

$(NAME) :
	@make -C ./srcs_asm
	@make -C ./srcs_corewar
	@mv ./srcs_asm/asm ./
	@mv ./srcs_corewar/corewar ./

clean :
	@make -C ./srcs_asm/ clean
	@make -C ./srcs_corewar/ clean

fclean : clean
	@make -C ./srcs_asm/ fclean
	@make -C ./srcs_corewar/ fclean
	@rm asm
	@rm corewar

re : fclean $(NAME)
