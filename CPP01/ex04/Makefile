# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikulik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 13:34:13 by vtrofyme          #+#    #+#              #
#    Updated: 2025/07/29 13:53:29 by ikulik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Replace

MAIN		= main.cpp Replace.cpp

MAINDIR		= src
MAINSRC		= $(addprefix $(MAINDIR)/, $(MAIN))
SRCSDIR		= src
OBJDIR		= obj
INCLUDE		= include

SRCS		= $(MAINSRC)

OBJS		= $(SRCS:$(SRCSDIR)/%.cpp=$(OBJDIR)/%.o)

CFLAGS		= -Wall -Wextra -Werror -g3 -std=c++98
INCLUDES	= -I$(INCLUDE)
CC			= g++

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBRARY) $(INCLUDES) -o $(NAME)

$(OBJDIR)/%.o: $(SRCSDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
