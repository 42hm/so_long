# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 12:10:57 by hmoon             #+#    #+#              #
#    Updated: 2022/05/19 21:46:46 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= so_long
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
RM				:= rm -f

LIBFT			:= ./libft/libft.a
LIBFT_DIR		:= ./libft/
LIBFT_HEADER	:= ./libft/include/

MLX_DIR			:= ./mlx/
MLX_LIB			:= libmlx.dylib

HEADER			:= ./include/
SRC_DIR			:= ./src/
OBJ_DIR			:= ./.obj/

HEADER_BONUS	:= ./bonus/include/
SRC_DIR_B		:= ./bonus/src/
OBJ_DIR_B		:= ./bonus/.obj/

SRC_FILES		:= $(addsuffix .c, )
OBJ_FILES		:= $(SRC_FILES:.c=.o)
SRC				:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_FILES_B		:= $(addsuffix .c, )
OBJ_FILES_B		:= $(SRC_FILES_B:.c=.o)
SRC_BONUS		:= $(addprefix $(SRC_DIR_B), $(SRC_FILES_B))
OBJ_BONUS		:= $(addprefix $(OBJ_DIR_B), $(OBJ_FILES_B))

ifdef BONUS
		INCLUDE			= $(HEADER_BONUS)
		SRC_FOLDER		= $(SRC_DIR_B)
		OBJ_FOLDER		= $(OBJ_DIR_B)
		OBJS			= $(OBJ_BONUS)
		PRINT			= BONUS
else
		INCLUDE			= $(HEADER)
		SRC_FOLDER		= $(SRC_DIR)
		OBJ_FOLDER		= $(OBJ_DIR)
		OBJS			= $(OBJ)
		PRINT			= SO_LONG
endif

.PHONY		: all
all			: mlx $(LIBFT) $(NAME)

$(NAME)		: $(OBJS)
	@$(CC) $(CFLAGS) $(MLX_LIB) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "\033[01;32m       SUCCESS!      \033[0m"

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_HEADER) -I$(INCLUDE) -o $@ -c $<

$(LIBFT)	:
	@make -C $(LIBFT_DIR) all

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
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(OBJS_BONUS) $(MLX_LIB)

.PHONY		: fclean
fclean		: clean
	@make -C ./libft fclean
	@$(RM) $(NAME)

.PHONY		: re
re			: fclean all
