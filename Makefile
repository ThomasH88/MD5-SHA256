# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2019/05/12 15:15:03 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

HEADER = $(addprefix includes/, ft_ssl.h)

LIB1 = libft/libft.a

LIB2 = ft_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -o

SRCS = $(addprefix srcs/, \
       algo_md5.c \
       bitwise_words.c \
	   exit_errors.c \
       flags.c \
       ft_md5.c \
	   ft_ssl.c \
       print_bits.c \
       process_message_md5.c \
       side_funct.c \
       side_md5.c) \
	   $(addprefix srcs/sha256/, \
	   algo_sha256.c \
	   ft_sha256.c \
	   process_message_sha256.c)

SRCO = $(SRCS:.c=.o)

$(NAME):
	make -C libft/
	make -C ft_printf/
	gcc $(FLAGS) $(NAME) $(SRCS) $(LIB1) $(LIB2) -I=$(HEADER)

all: $(NAME)

san: fclean
	make -C libft/
	make -C ft_printf/
	gcc -fsanitize=address -g $(FLAGS) $(NAME) $(SRCS) $(LIB1) $(LIB2) -I=$(HEADER)

clean:
	make clean -C libft/
	make clean -C ft_printf/
	/bin/rm -f $(SRCO)

fclean: clean
	make fclean -C libft/
	make fclean -C ft_printf/
	/bin/rm -rf $(NAME) *.out* *.dSYM

re: fclean all

git: fclean
	git add .
	git reset HEAD *main*
	git status
	git commit -m "update"
	git push
