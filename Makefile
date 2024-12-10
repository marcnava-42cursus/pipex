# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 04:37:29 by marcnava          #+#    #+#              #
#    Updated: 2024/12/10 21:31:43 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		VARIABLES	#

NAME		=	pipex

CC			=	cc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

COMPILER	=	$(CC) $(CFLAGS) -I

INCLUDE		=	./pipex.h

# **************************************************************************** #
#		FOLDERS		#

SRCSPATH	=	./src
LIBS		=	./libs/libft

# **************************************************************************** #
#		FILES		#

SRCS 		=	pipex.c				\
				message_handler.c	\
				processes.c			\
				pipex_utils.c

OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
#		RULES		#

all: 			compiling $(NAME)

$(LIBS)/libft.a:
				@$(MAKE) --no-print-directory -C $(LIBS)

$(NAME):		$(OBJS) $(LIBS)/libft.a
				@$(COMPILER) $(INCLUDE) $(OBJS) $(LIBS)/libft.a -o $(NAME)
				@$(MAKE) --no-print-directory -C $(LIBS) fclean
				@printf "Compiled.\n"

%.o:			%.c
				@$(COMPILER) $(INCLUDE) -c $< -o $@

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

compiling:
				@printf "Compiling program...\n"

re:				fclean all

.PHONY:			all clean fclean re compiling
