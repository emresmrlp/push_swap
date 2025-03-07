# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 12:12:01 by ysumeral          #+#    #+#              #
#    Updated: 2025/03/07 15:27:46 by ysumeral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
LIB_DIR = ./external/libft
INC_DIR = ./include
PRINTF_LIB = ./external/ft_printf/libftprintf.a
SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/stack_push.c \
		$(SRC_DIR)/stack_swap.c \
		$(SRC_DIR)/stack_rotate.c \
		$(SRC_DIR)/stack_util.c \
		$(SRC_DIR)/sort_handler.c \
		$(SRC_DIR)/sort_util.c \
		$(SRC_DIR)/sort_quicksort.c \
		$(SRC_DIR)/sort_algorithms.c \
		$(SRC_DIR)/stack_rev_rotate.c \
		$(SRC_DIR)/program_init.c \
		$(SRC_DIR)/program_state.c \
		$(SRC_DIR)/param_handler.c \
		$(SRC_DIR)/stack_handler.c \
		$(SRC_DIR)/memory_free.c \
		$(LIB_DIR)/ft_calloc.c \
		$(LIB_DIR)/ft_atol.c \
		$(LIB_DIR)/ft_split.c \
		$(LIB_DIR)/ft_putstr_fd.c \
		$(LIB_DIR)/ft_substr.c \
		$(LIB_DIR)/ft_strdup.c \
		$(LIB_DIR)/ft_strlcpy.c \
		$(LIB_DIR)/ft_strncmp.c \
		$(LIB_DIR)/ft_strlen.c \
		$(LIB_DIR)/ft_strchr.c \
		$(LIB_DIR)/ft_isdigit.c \
		$(LIB_DIR)/ft_strrchr.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./external/ft_printf
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ${PRINTF_LIB}

clean:
	make clean -C ./external/ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./external/ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re