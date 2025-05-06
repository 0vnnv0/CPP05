# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anna <anna@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 14:16:05 by anschmit          #+#    #+#              #
#    Updated: 2025/05/05 18:58:38 by anna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BUREAUCRAT

SRC = main.cpp Bureaucrat.cpp Form.cpp

CXX = c++

OBJS = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

%.o: %.cpp
	@echo "$(YELLOW) Compiling $< ... $(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN) Executable $(NAME) created.$(RESET)"

clean:
		@echo "$(GREEN)Cleaning object files...$(RESET)"
		@rm -f $(OBJS)

fclean: clean
		@echo "$(GREEN)Removing executable ..."
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean