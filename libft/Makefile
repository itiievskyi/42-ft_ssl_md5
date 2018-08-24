# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 17:15:33 by itiievsk          #+#    #+#              #
#    Updated: 2018/03/20 17:19:15 by itiievsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

DIR_S = ./

DIR_O = obj

HEADER = libft.h

SOURCES =	ft_atoi.c\
			ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_lstadd.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putchar.c\
			ft_putendl_fd.c\
			ft_putendl.c\
			ft_putnbr_fd.c\
			ft_putnbr.c\
			ft_putstr_fd.c\
			ft_putstr.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			get_next_line.c\
			ft_printf_chars.c\
			ft_printf_double.c\
			ft_printf_hex.c\
			ft_printf_ints.c\
			ft_printf_oct.c\
			ft_printf_params.c\
			ft_printf_strings.c\
			ft_printf_struct.c\
			ft_printf_unicode.c\
			ft_printf_utils.c\
			ft_printf.c\
			ft_write.c\
			ft_wstrdup.c\
			ft_strnchr.c\
			get_word.c\
			ft_lstpushback.c\
			ft_words_count.c\
			ft_count_in_array.c\
			ft_isdigit_str.c\
			ft_sort_strtab.c\
			ft_intlen.c\
			ft_clean_str_array.c\
			ft_strcmp_nocase.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	@norminette $(HEADER)
	@norminette $(SOURCES)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
