# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 20:46:56 by fcoullou          #+#    #+#              #
#    Updated: 2024/04/24 13:53:32 by fcoullou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

#------------------------------------------------#

SRC_PATH	= src
OBJ_PATH	= obj
INC_PATH	= include

SRC		= $(wildcard $(SRC_PATH)/*.c)
OBJ		= $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)


AR			:= ar
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I./includes

RM			:= rm -f
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rcs $(NAME) $(OBJ)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	$(CC) -nostartfiles -shared -o libft.so $(OBJ)
		
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
			
clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_PATH)

re: fclean all