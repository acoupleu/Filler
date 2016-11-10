# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 21:47:41 by acoupleu          #+#    #+#              #
#    Updated: 2016/09/27 18:16:08 by acoupleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	acoupleu.filler
FLAGS			=	-Wall -Wextra -Werror -g
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft
INCLUDES		=	-I $(LIB_PATH)/includes -I ./includes
SRCS			=	srcs/main.c srcs/parsing.c srcs/checker.c srcs/moves.c \
					srcs/parsing_pos.c
OBJS			=	$(SRCS:srcs/%.c=obj/%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[34m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	[ $(C_GOOD)OK$(C_NO) ]
OK				=	[ $(C_OK)OK$(C_NO) ]


all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

obj/%.o: srcs/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all
