# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/01 16:58:07 by ypacileo          #+#    #+#              #
#    Updated: 2026/03/01 16:59:17 by ypacileo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Bureaucrat
SRC =  Bureaucrat.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all