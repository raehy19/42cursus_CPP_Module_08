# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 04:30:10 by rjeong            #+#    #+#              #
#    Updated: 2024/09/08 04:30:11 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex00

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP
RM := rm -f

all : $(NAME)

SRCS := \
	main.cpp

OBJS := \
	$(SRCS:.cpp=.o)

DEPS := \
	$(SRCS:.cpp=.d)

-include $(DEPS)

clean :
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	make all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re



