# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 12:10:57 by hmoon             #+#    #+#              #
#    Updated: 2022/03/30 17:08:09 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

MLX_DIR		:= ./mlx/
MLX_LIB		:= libmlx.dylib

SRCS_DIR	:= ./srcs/
SRCS		:= $(addprefix $(SRCS_DIR), )
OBJS		:= $(SRCS:.c=.o)

BONUS_DIR	:= ./bonus/
SRCS_BONUS	:= $(addprefix $(BONUS_DIR), )
OBJS_BONUS	:= $(SRCS_BONUS:.c=.o)

ifdef BONUS
		OBJ	= $(OBJS_BONUS)
		DIR	= $(BONUS_DIR)
else
		OBJ	= $(OBJS)
		DIR	= $(SRCS_DIR)
endif

.PHONY		: all
all			: mlx $(NAME)

$(NAME)		: $(MLX_LIB) $(OBJS)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o			: %.c
		$(CC) $(CFLAGS) -I$(DIR) -c $< -o $@

.PHONY		: bonus
bonus		:
		@make BONUS=1 all

.PHONY		: mlx
mlx			:
		@make -C $(MLX_DIR)
		cp $(MLX_DIR)$(MLX_LIB) .

.PHONY		: clean
clean		:
		@make -C $(MLX_DIR) clean
		$(RM) $(OBJS) $(OBJS_BONUS) $(MLX_LIB)

.PHONY		: fclean
fclean		: clean
		$(RM) $(NAME)

.PHONY		: re
re			: fclean all
