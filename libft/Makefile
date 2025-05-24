# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 09:37:48 by hfilipe-          #+#    #+#              #
#    Updated: 2025/05/24 08:51:54 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -I includes

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c \
	ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	get_next_line_utils.c get_next_line.c ft_lstnew.c ft_lstadd_front.c\
	ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
MAIN_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(MAIN_SRCS))

NAME = libft.a

FT_PRINTF_DIR = ft_printf_fd

all: $(NAME) $(EXEC)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(EXEC): $(MAIN_OBJ) $(FT_PRINTF_DIR)/ft_printf_fd.a
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(FT_PRINTF_DIR)/ft_printf_fd.a

$(FT_PRINTF_DIR)/ft_printf_fd.a:
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(EXEC)

re: fclean all