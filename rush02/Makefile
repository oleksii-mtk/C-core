# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 12:00:00 by user42            #+#    #+#              #
#    Updated: 2024/08/18 22:29:21 by omatyko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = rush-02

# Source files
SRCS = rush-02.c ft_str.c ft_put.c ft_parse_dict.c ft_convertion.c ft_atoi.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
INCLUDES = ft_h.h

# Build the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Clean object files and the executable
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean $(NAME)

# Specify phony targets
.PHONY: all clean fclean re

