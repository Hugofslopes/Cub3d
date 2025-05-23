# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 09:37:48 by hfilipe-          #+#    #+#              #
#    Updated: 2025/05/23 20:07:29 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -I includes


SRC = ft_printf_fd.c

MAIN_SRCS = main.c

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
BONUS_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(BONUS_SRCS))
MAIN_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(MAIN_SRCS))

NAME = ft_printf_fd.a
EXEC = main

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(EXEC)

re: fclean all