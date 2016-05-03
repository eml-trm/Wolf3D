# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/14 13:39:15 by etermeau          #+#    #+#              #
#    Updated: 2015/05/25 18:00:54 by etermeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIB = libft/

HEADER = includes/

HEADER_X11 = /Volumes/Mac\ OS/System/Library/Frameworks/Tk.framework/Headers/X11

HEADER_MLX = /usr/local/include/

DIRSRC = srcs/

FLAGS = -Wall -Wextra -Werror -g

SRC = main.c \
	  move.c \
	  draw.c \
	  draw2.c \
	  color.c \
	  init_map.c \
	  init.c 
	  
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft -lmlx -framework OpenGL -framework AppKit -g -L/usr/local/lib
	@echo "\033[5;32m$(NAME) Successfully $(STATE)\033[0m"

%.o: $(DIRSRC)%.c
	@gcc $(FLAGS) -o $@ -c $< -I$(LIB)$(HEADER) -I$(HEADER) -I$(HEADER_X11) -I$(HEADER_MLX)
clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIB)
	@echo "\033[5;32mDelete all files.o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIB)
	@echo "\033[5;32mDelete $(NAME)\033[0m"

re: fclean all
