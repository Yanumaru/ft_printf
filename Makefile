#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/26 07:10:14 by ykichena          #+#    #+#              #
#    Updated: 2014/10/26 11:14:07 by ykichena         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_print_str.c\
	my_ltoa.c\
	ft_printf.c\
	my_uitoa.c\
	my_ultoa.c\
	continue_to_print.c\
	ft_award.c\
	get_opt.c\
	ft_end_printf.c\
	ft_print_car.c\
	ft_print_num.c\
	my_itoa.c

LIB_SRC = ft_memset.c\
    ft_bzero.c\
    ft_memcpy.c\
    ft_memccpy.c\
    ft_memmove.c\
    ft_memchr.c\
    ft_memcmp.c\
    ft_strlen.c\
    ft_strdup.c\
    ft_strcpy.c\
    ft_strncpy.c\
    ft_strcat.c\
    ft_strncat.c\
    ft_strlcat.c\
    ft_strchr.c\
    ft_strrchr.c\
    ft_strstr.c\
    ft_strnstr.c\
    ft_strcmp.c\
    ft_strncmp.c\
    ft_atoi.c\
    ft_isalpha.c\
    ft_isdigit.c\
    ft_isalnum.c\
    ft_isascii.c\
    ft_isprint.c\
    ft_toupper.c\
    ft_tolower.c\
    ft_memalloc.c\
    ft_memdel.c\
    ft_strnew.c\
    ft_strclr.c\
    ft_striter.c\
    ft_strmap.c\
    ft_strequ.c\
    ft_strsub.c\
    ft_strjoin.c\
    ft_strtrim.c\
    ft_strsplit.c\
    ft_strdel.c\
    ft_striteri.c\
    ft_strmapi.c\
    ft_strnequ.c\
    ft_itoa.c\
    ft_putchar.c\
    ft_putstr.c\
    ft_putendl.c\
    ft_putnbr.c\
    ft_putchar_fd.c\
    ft_putstr_fd.c\
    ft_putendl_fd.c\
    ft_putnbr_fd.c\
    get_next_line.c

DIR = libft/

OBJ = $(SRC:.c=.o)

LIB_OBJ = $(patsubst %.c, $(DIR)%.o, $(LIB_SRC))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIB_OBJ)
	@ranlib $(NAME)

%.o: %.c
	@make -C $(DIR)
	@gcc $(FLAGS) -c $(SRC) -I $(DIR)includes

clean:
	@make clean -C $(DIR)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
