# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 16:43:19 by jedelfos          #+#    #+#              #
#    Updated: 2021/12/13 15:23:13 by jedelfos         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC=clang++
CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c++98

NAME=convert

SRCS =	main.cpp \
		TypeId.cpp

OBJS=$(SRCS:.cpp=.o)

RM=rm -f

INC=	TypeId.hpp

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)
$(OBJS):	$(INC)

$(NAME): 	$(INC) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re