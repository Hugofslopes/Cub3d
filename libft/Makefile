# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 09:37:48 by hfilipe-          #+#    #+#              #
#    Updated: 2025/06/09 09:32:45 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Werror -Wextra -Wall
INCLUDES = -I includes
SRC_DIR = src
OBJ_DIR = obj

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_putendl_fd.c ft_putnbr_fd.c \
    ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
    ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
    ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
    ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c \
    ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
    get_next_line_utils.c get_next_line.c ft_lstnew.c ft_lstadd_front.c \
    ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
    ft_lstiter.c ft_lstmap.c

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

NAME = libft.a
LIBFT_ARC = $(NAME)

all:  $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all