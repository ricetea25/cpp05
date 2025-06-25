# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 01:50:51 by rteoh             #+#    #+#              #
#    Updated: 2025/06/24 19:18:28 by rteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Bureaucrat
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -pedantic
RM			:= rm -f
SOURCES		:= main.cpp Bureaucrat.cpp
OBJECTS 	:= $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
