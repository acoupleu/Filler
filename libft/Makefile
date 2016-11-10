# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 22:21:01 by acoupleu          #+#    #+#              #
#    Updated: 2016/06/01 20:27:51 by acoupleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME		=	libft.a
FLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ./includes

SRCS	=	srcs/ft_memalloc.c srcs/ft_memccpy.c srcs/ft_memchr.c	\
			srcs/ft_memcmp.c srcs/ft_memcpy.c srcs/ft_memdel.c		\
			srcs/ft_memmove.c srcs/ft_memset.c srcs/ft_bzero.c		\
			srcs/ft_memset_int.c srcs/ft_memalloc_int.c			 		\
			\
			srcs/ft_isalnum.c srcs/ft_isalpha.c srcs/ft_isascii.c			\
			srcs/ft_isdigit.c srcs/ft_isprint.c srcs/ft_itoa.c				\
			srcs/ft_oitoa.c srcs/ft_uitoa.c srcs/ft_xitoa.c srcs/ft_abs.c	\
			srcs/ft_atoi.c srcs/ft_atoll.c srcs/ft_sqrt.c srcs/ft_tolower.c	\
			srcs/ft_toupper.c srcs/ft_isablank.c srcs/ft_isspace.c			\
			\
			srcs/ft_putchar.c srcs/ft_putchar_fd.c srcs/ft_putendl.c		\
			srcs/ft_putendl_fd.c srcs/ft_putnbr.c srcs/ft_putnbr_fd.c		\
			srcs/ft_putstr.c srcs/ft_putstr_fd.c							\
			\
			srcs/ft_strcat.c srcs/ft_strchr.c srcs/ft_strclr.c		\
			srcs/ft_strcmp.c srcs/ft_strcpy.c srcs/ft_strdel.c		\
			srcs/ft_strdup.c srcs/ft_strequ.c srcs/ft_striter.c		\
			srcs/ft_striteri.c srcs/ft_strjoin.c srcs/ft_strlcat.c	\
			srcs/ft_strlen.c srcs/ft_strmap.c srcs/ft_strmapi.c		\
			srcs/ft_strncat.c srcs/ft_strncmp.c srcs/ft_strncpy.c	\
			srcs/ft_strnequ.c srcs/ft_strnew.c srcs/ft_strnstr.c	\
			srcs/ft_strrchr.c srcs/ft_strsplit.c srcs/ft_strstr.c	\
			srcs/ft_strsub.c srcs/ft_strtrim.c srcs/ft_cnt_word.c	\
			\
			srcs/ft_lstnew.c srcs/ft_lstdelone.c srcs/ft_lstdel.c	\
			srcs/ft_lstadd.c srcs/ft_lstiter.c srcs/ft_lstmap.c		\
			\
			srcs/get_next_line.c

FT_PRINTF	=	srcs/ft_printf/ft_printf.c								\
				\
				srcs/ft_printf/parse_flags.c srcs/ft_printf/parse_option.c	\
				\
				srcs/ft_printf/c_flag.c	srcs/ft_printf/wc_flag.c			\
				srcs/ft_printf/s_flag.c	srcs/ft_printf/ws_flag.c			\
				srcs/ft_printf/d_flag.c										\
				srcs/ft_printf/u_flag.c										\
				srcs/ft_printf/x_flag.c	srcs/ft_printf/xu_flag.c			\
				srcs/ft_printf/o_flag.c										\
				srcs/ft_printf/p_flag.c	srcs/ft_printf/perc_flag.c			\
				\
				srcs/ft_printf/print_flags.c srcs/ft_printf/tools.c			\

OBJS			=	$(SRCS:srcs/%.c=obj/%.o)
OBJS_PRINTF		=	$(FT_PRINTF:srcs/ft_printf/%.c=obj/%.o)

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

$(NAME): $(OBJS) $(OBJS_PRINTF)
	@ar -rc $(NAME) $(OBJS) $(OBJS_PRINTF)
	@ranlib	$(NAME)
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

obj:
	@mkdir -p obj

obj/%.o: srcs/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

obj/%.o: srcs/ft_printf/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

clean:
	@rm -rf obj
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean: clean
	@rm -f $(NAME)
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all
