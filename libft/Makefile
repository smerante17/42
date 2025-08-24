# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerante <smerante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 16:02:40 by smerante          #+#    #+#              #
#    Updated: 2025/08/14 15:11:05 by smerante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
#name of the utilized compiler
CC = cc
#flags to compile with
CFLAGS = -Wall -Wextra -Werror
#source file to read
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c\
	ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
	
#instruction to put for every file created a .o extension(conversion)
OBJS = $(SRCS:.c=.o)
#create the library
all: $(NAME)
#instructions to create the library with the objects
$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)
#instruction for how to compile the source, based on header (-c to separate the *.o files)
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
#delete the objects created\cleaning
clean:
	rm -f $(OBJS)
#intense cleaning, remove the library created
fclean: clean
	rm -f $(NAME)
#recompile all after the cleaning
re: fclean all
#declare that this words are only commands and not a files to generate
.PHONY: all clean fclean re