# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damarry <damarry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 20:36:29 by damarry           #+#    #+#              #
#    Updated: 2021/11/19 21:49:51 by damarry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= Libft
LIBFT_LIB	= Libft.a

SRCS	= ./print_ustr.c\
		  	./printf.c\
		  	./print_uflags.c\
		  	./print_unbr.c\
		  	./printf_utils.c

SRCS_B	= ./print_ustr_bonus.c\
		  	./printf_bonus.c\
		  	./print_uflags_bonus.c\
		  	./print_unbr_bonus.c\
		  	./printf_utils_bonus.c
			  
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
INCS	= .
RM		= rm -f
LIBC	= ar rc
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME) bonus

bonus : $(OBJS_B)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)

re : fclean all