# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 09:37:48 by hfilipe-          #+#    #+#              #
#    Updated: 2025/05/26 11:17:12 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -I includes

SRC = ft_printf_fd.c ft_pf_putchar.c ft_pf_putnbr_hex.c ft_pf_putnbr_p.c \
    ft_pf_putnbr_ui.c ft_pf_putnbr.c ft_putstr_fd.c pf_bzero.c

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

NAME = ft_printf_fd.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all