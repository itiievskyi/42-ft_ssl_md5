# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 14:51:09 by itiievsk          #+#    #+#              #
#    Updated: 2018/08/06 10:15:14 by itiievsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = ft_ssl

FLAGS = -Wall -Wextra -Werror

DIR_S = ./

DIR_O = obj

HEADER =	ft_ssl.h

LIB = libft/libft.a

SOURCES =	main.c \
			ft_strjoin_size.c \
			ft_itoa_hex.c \
			errors.c \
			io.c \
			utils.c \
			md5_read.c \
			md5_encrypt.c \
			sha224.c \
			sha256_read.c \
			sha256_encrypt.c \
			sha_print.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(C) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	$(C) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	@norminette $(HEADER)
	@norminette $(SOURCES)
	make norme -C ./libft/

clean:
	make clean -C ./libft/
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	make fclean -C ./libft/
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
