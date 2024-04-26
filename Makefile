# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:34:03 by fcoullou          #+#    #+#              #
#    Updated: 2024/04/26 17:07:35 by fcoullou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------#
NAME			= so_long									
#------------------------------------------------#
SRC_PATH		= src
INC_PATH		= include
OBJ_PATH		= obj

INC				= /usr/local/include
LIBMLX			= /usr/local/lib
LIBFT			= ./libft

CFLAGS			= -Wall -Werror -Wextra -I./mlx -I./include -I./libft/include -g3

SRC				= $(SRC_PATH)/anim_player_and_tokens.c \
				$(SRC_PATH)/anim_utils.c \
				$(SRC_PATH)/end.c \
				$(SRC_PATH)/free_utils.c \
				$(SRC_PATH)/game_launch.c \
				$(SRC_PATH)/game_setup.c \
				$(SRC_PATH)/main.c \
				$(SRC_PATH)/map_check.c \
				$(SRC_PATH)/map_setup.c \
				$(SRC_PATH)/player_actions.c \
				$(SRC_PATH)/utils.c

OBJ				= $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
OUTPUT_LEAKS 	= valgrind-out.txt
#------------------------------------------------#
AR				= ar
CC				= cc
RM				= rm -f
CD				= cd
DIR_DUP			= mkdir -p $(@D)
#------------------------------------------------#
LFLAGS 			=  -L./mlx -L./libft -lft -lbsd -lXext -lX11 -lmlx 
#------------------------------------------------#
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make -C mlx
	@printf "CREATED $@\n"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS) 
	@printf "CREATED $@\n"

echo:
	echo $(CFLAGS)	

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(DIR_DUP)
	$(CC) $(CFLAGS) -c $< -o $@ 
		
clean:
	@make -C $(LIBFT) clean
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_PATH)
	$(RM) -r $(LIBFT_OBJ)

fclean: clean
	@make -C $(LIBFT) fclean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_PATH)
	
re: fclean all
#------------------------------------------------#
leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(OUTPUT_LEAKS) ./$(NAME)
	@cat valgrind-out.txt

.PHONY: leaks fclean clean all re
#------------------------------------------------#
