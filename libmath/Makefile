# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 11:28:35 by roster            #+#    #+#              #
#    Updated: 2019/10/09 10:31:02 by reda-con         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmath.a

SRCS_LIBMATH = cross_product.c	\
			   dot_vec.c		\
			   move_pt.c		\
			   size_vec.c		\
			   unit_vec.c		\
			   add_pt.c			\
			   deg_to_rad.c		\
			   equation_2_deg.c	\
			   mul_vec.c		\
			   sub_pt.c			\
			   vec.c			\
			   add_vec.c		\
			   div_vec.c		\
			   rad_to_deg.c		\
			   sub_vec.c

SRCS = $(SRCS_LIBMATH)

INCLUDE = libmath.h

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRCS) -I $(INCLUDE) | echo "\x1b[35m ✓ Creation of .o\x1b[0m"
	@ar rc $(NAME) $(OBJS) | echo "\x1b[32m ✓ Creation of $(NAME)\x1b[0m"
	@ranlib $(NAME) | echo "\x1b[33m 〢Indexing $(NAME)\x1b[0m"

clean:
	@/bin/rm -f $(OBJS) | echo "\x1b[31m ✗ Deleting .o\x1b[0m"

fclean: clean
	@/bin/rm -f $(NAME) | echo "\x1b[31m ✗ Deleting $(NAME)\x1b[0m"

re: 
	@Make fclean
	@Make all

again: 
	@Make re
	@Make clean
