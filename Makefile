# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 04:37:29 by marcnava          #+#    #+#              #
#    Updated: 2025/03/20 10:22:31 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		VARIABLES	#

NAME		=	pipex

CC			=	cc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror -g3

COMPILER	=	$(CC) $(CFLAGS)


# **************************************************************************** #
#		FOLDERS		#

SRCSPATH	=	./src
BONUS		=	./_bonus
BUILD		=	./build
ANIMATION	=	./animation
INCLUDE		=	./includes

LIBFT		=	./libs/libft

# **************************************************************************** #
#		FILES		#

FRAMES		=	$(ANIMATION)/f1.c  $(ANIMATION)/f2.c  $(ANIMATION)/f3.c		\
				$(ANIMATION)/f4.c  $(ANIMATION)/f5.c  $(ANIMATION)/f6.c		\
				$(ANIMATION)/f7.c  $(ANIMATION)/f8.c  $(ANIMATION)/f9.c		\
				$(ANIMATION)/f10.c $(ANIMATION)/f11.c $(ANIMATION)/f12.c	\
				$(ANIMATION)/f13.c $(ANIMATION)/f14.c $(ANIMATION)/f15.c	\
				$(ANIMATION)/f16.c $(ANIMATION)/f17.c $(ANIMATION)/f18.c	\
				$(ANIMATION)/f19.c $(ANIMATION)/f20.c $(ANIMATION)/f21.c	\
				$(ANIMATION)/f22.c $(ANIMATION)/f23.c $(ANIMATION)/f24.c	\
				$(ANIMATION)/f25.c $(ANIMATION)/f26.c $(ANIMATION)/f27.c	\
				$(ANIMATION)/f28.c $(ANIMATION)/f29.c $(ANIMATION)/f30.c	\
				$(ANIMATION)/f31.c $(ANIMATION)/f32.c $(ANIMATION)/f33.c

SRCS 		=	$(SRCSPATH)/error_handler.c									\
				$(SRCSPATH)/get_path.c										\
				$(SRCSPATH)/pipex_utils.c									\
				$(SRCSPATH)/pipex.c											\
				$(SRCSPATH)/processes.c

SRCS_BONUS	=	$(BONUS)/error_handler_bonus.c								\
				$(BONUS)/here_doc_bonus.c									\
				$(BONUS)/pipe_manager_bonus.c								\
				$(BONUS)/pipex_bonus.c										\
				$(BONUS)/pipex_utils_bonus.c

OBJS		=	$(SRCS:$(SRCSPATH)/%.c=$(BUILD)/%.o)
OBJS_BONUS	=	$(SRCS_BONUS:$(BONUS)/%.c=$(BUILD)/%.o)

# **************************************************************************** #
#		RULES		#

run:
				# @make -s animate &
				@$(MAKE) -s all
				@wait $$!
.PHONY: run

all:			$(LIBFT)/libft.a $(NAME)
.PHONY: all

$(NAME):		$(OBJS)
				@$(COMPILER) -I$(INCLUDE) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

$(LIBFT)/libft.a:
				@$(MAKE) --no-print-directory -s -C $(LIBFT)

$(BUILD)/%.o:	$(SRCSPATH)/%.c
				@mkdir -p $(@D)
				@$(COMPILER) -I$(INCLUDE) -c $< -o $@

# $(BUILD)/%.o:	$(BONUS)/%.c
# 				@mkdir -p $(@D)
# 				@$(COMPILER) -I$(INCLUDE) -c $< -o $@

bonus:			$(OBJS_BONUS) $(LIBFT)/libft.a
				@$(COMPILER) -I$(INCLUDE) $(OBJS_BONUS) $(LIBFT)/libft.a -o $(NAME)
.PHONY: bonus

clean:
				@$(RM) $(BUILD)
				@$(MAKE) --no-print-directory -s -C $(LIBFT) clean
.PHONY: clean

fclean:			clean
				@$(RM) $(NAME)
				@$(MAKE) --no-print-directory -s -C $(LIBFT) fclean
.PHONY: fclean

re:				fclean run
.PHONY: re

animate:
				@for frame in $(FRAMES); do \
					clear; \
					echo "\033[38;5;46m"; \
					sed '1,13d; $$d' $$frame; \
					echo "\033[0m"; \
					sleep 0.1; \
				done
.PHONY: animate
