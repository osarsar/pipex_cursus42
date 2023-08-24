# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 08:50:01 by osarsar           #+#    #+#              #
#    Updated: 2023/05/12 15:02:51 by osarsar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c	\
	pipex_utils.c	\

NAME = libft.a

%.o : %.c pipex.h
	@echo "Compiling: $<"
	@cc -Wall -Werror -Wextra  -c $< -o $@

$(NAME) : $(SRCS:.c=.o)
	@make all -C libft
	@cp libft/libft.a .
	@ar -r $(NAME) $(SRCS:.c=.o)
	@cc pipex.c libft.a -o pipex

all : $(NAME)

clean :
	@rm -f $(SRCS:.c=.o)
	@make clean -C libft

fclean : clean
	@rm -f libft.a
	@make fclean -C libft
	@make fclean -C pipex_bonus
	@rm -f pipex

re : fclean all

bonus :
	make -C pipex_bonus