# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 04:37:29 by marcnava          #+#    #+#              #
#    Updated: 2025/01/29 16:15:20 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		VARIABLES	#

NAME		=	pipex

CC			=	cc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

COMPILER	=	$(CC) $(CFLAGS) -I

INCLUDE		=	.

# **************************************************************************** #
#		FOLDERS		#

SRCSPATH	=	./src
LIBS		=	./libs/libft
BONUS		=	./_bonus

# **************************************************************************** #
#		FILES		#

SRCS 		=	error_handler.c					\
				pipex_utils.c					\
				pipex.c							\
				processes.c

SRCS_BONUS	=	$(BONUS)/error_handler_bonus.c	\
				$(BONUS)/here_doc_bonus.c		\
				$(BONUS)/pipe_manager_bonus.c	\
				$(BONUS)/pipex_bonus.c			\
				$(BONUS)/pipex_utils_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

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

bonus:			$(OBJS_BONUS) $(LIBS)/libft.a
				@$(COMPILER) $(INCLUDE) $(OBJS_BONUS) $(LIBS)/libft.a -o $(NAME)
				@$(MAKE) --no-print-directory -C $(LIBS) fclean
				@printf "Compiled.\n"

clean:
				@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				@$(RM) $(NAME)

compiling:
				@printf "Compiling program...\n"

re:				fclean all

.PHONY:			all clean fclean re compiling bonus
