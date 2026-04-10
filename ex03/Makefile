# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 03:37:18 by ssadi-ou          #+#    #+#              #
#    Updated: 2026/04/09 20:14:10 by ssadi-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Intern \

SRCS	= main.cpp \
	  Bureaucrat.cpp \
	  AForm.cpp \
	  ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp \
	  PresidentialPardonForm.cpp \
	  Intern.cpp \

OBJS	= $(SRCS:.cpp=.o)

CXX	= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -Wno-shadow -fdiagnostics-color=always -std=c++98

all:	$(NAME)

$(OBJS): Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
