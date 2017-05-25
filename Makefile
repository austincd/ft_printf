#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 14:16:26 by adaly             #+#    #+#              #
#    Updated: 2017/05/24 19:28:32 by adaly            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libftprintf.a

FLAGS= -c -Wall -Wextra -Werror

INCLUDES= ./

SRCS= ft_argument_handling.c ft_evaluate.c ft_printf.c ft_float.c ft_import_type.c 

OBJECTS= ft_argument_handling.o ft_evaluate.o ft_printf.o ft_float.o ft_import_type.o

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -I$(INCLUDES) $(SRCS)
		ar rc $(NAME) $(OBJECTS) libft.a
clean: 
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
