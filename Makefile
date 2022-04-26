# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrings <hrings@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:17:49 by hrings            #+#    #+#              #
#    Updated: 2022/03/02 11:29:43 by hrings           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

CC = gcc
uname_S := $(shell uname -s)

ifeq ($(uname_S), Linux)
	MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
	MINILIBX_DIRECTORY = ./minilibx-linux/
	MLX_INC	= -I minilibx-linux
	MLX_LNK	= -Lminilibx-linux -lm -lmlx -lXext -lX11 -Iminilibx-linux
endif
ifeq ($(uname_S), Darwin)
	MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
	MINILIBX_DIRECTORY = ./minilibx_macos/
	MLX_INC	= -I minilibx_macos
	MLX_LNK	= -Lminilibx_macos -lm -lmlx -framework OpenGL -framework AppKit -Iminilibx_macos
endif

CFLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = $(FT_LNK) $(MLX_LNK)
INCLUDES = $(MLX_INC) $(FT_INC)
HEADER = ./header
SRCDIR = src/

LIBFT = $(LIBFT_DIRECTORY)/libft.a
LIBFT_DIRECTORY = ./libft
FT_INC	= -I ./libft/
FT_LNK	= ./libft/libft.a


OBJDIR = build/

SRCS := main.c keyhandle.c mapreader.c drawing.c parser.c \
		bresenham.c projection.c transform.c rotation.c \
		utilities.c keyhandle2.c color.c menu.c menu2.c \
		projection2.c

OBJECTS := $(SRCS:.c=.o)
OBJECTS_PREFIXED := $(addprefix $(OBJDIR), $(OBJECTS))


GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) objdir $(OBJECTS_PREFIXED)
	$(CC) $(CFLAGS) $(OBJECTS_PREFIXED) $(LIBRARIES) -I$(HEADER) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

objdir:
	@mkdir -p $(OBJDIR)

$(OBJECTS_PREFIXED): build/%.o : src/%.c
	$(CC) $(CFLAGS) -c  $< -o $@ -I$(HEADER) $(INCLUDES)
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) all -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	#@cd ./$(LIBFT_DIRECTORY) && make clean
	#@cd ./$(MINILIBX_DIRECTORY) &&  make clean
	@rm -rf $(OBJDIR)
	@echo "$(NAME): $(RED)object files and directory were deleted$(RESET)"

fclean: clean
	@cd ./$(LIBFT_DIRECTORY) && make fclean
	@cd ./$(MINILIBX_DIRECTORY) &&  make clean
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)Libaries were deleted$(RESET)"

re: fclean all
