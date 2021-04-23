# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 13:34:09 by amaza-va          #+#    #+#              #
#    Updated: 2020/01/26 19:35:43 by amaza-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER	=	minishell.h

SRCS	=	minishell.c					\
			minishell_utils.c			\
			minishell_ft_split.c		\
			minishell_input.c			\
			minishell_command_cd.c		\
			minishell_command_pwd.c		\
			minishell_command_echo.c	\
			minishell_command_na.c		\
			minishell_command_exit.c	\
			minishell_initialization.c	\
			minishell_variables.c		\
			minishell_command_parser.c	\

all	:	$(SRCS)
		@gcc $(SRCS) && ./a.out

clean	:
		@/bin/rm -f $(OBJS)

fclean	:	clean
		@/bin/rm -f $(NAME)

re		: 	fclean all