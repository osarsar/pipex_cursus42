# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 08:50:01 by osarsar           #+#    #+#              #
#    Updated: 2023/05/12 14:57:30 by osarsar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex_bonus.c	\
	pipex_utils_bonus.c	\
	get_next_line.c		\
	get_next_line_utils.c	\

NAME = libft.a

%.o : %.c pipex.h
	@echo "Compiling: $<"
	@cc -Wall -Werror -Wextra  -c $< -o $@

$(NAME) : $(SRCS:.c=.o)
	@make all -C libft
	@cp libft/libft.a .
	@ar -r $(NAME) $(SRCS:.c=.o)
	@cc pipex_bonus.c libft.a -o pipex
	@mv pipex ../

all : $(NAME)

clean :
	@rm -f $(SRCS:.c=.o)
	@make clean -C libft

fclean : clean
	@rm -f libft.a
	@make fclean -C libft
	@rm -f pipex

re : fclean all
