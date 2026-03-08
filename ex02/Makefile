# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/01 16:58:07 by ypacileo          #+#    #+#              #
#    Updated: 2026/03/08 18:00:24 by ypacileo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = a.out
SRC =  AForm.cpp Bureaucrat.cpp main.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all