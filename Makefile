# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 19:34:34 by svkhacha          #+#    #+#              #
#    Updated: 2022/07/25 14:22:23 by svkhacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

%o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo -e "$(GREEN)$(NAME) created !$(END)"

clean:
	$(RM) $(OBJS)
	@echo -e "$(BLUE) object files deleted !$(END)"

fclean: clean
	$(RM) $(NAME)
	@echo -e "$(YELLOW) all deleted !$(END)"

re: fclean all

.PHONY: all clean fclean re

#Makefile_Colors
GREEN = \033[1;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
END = \033[0m 

