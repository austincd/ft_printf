#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 14:16:26 by adaly             #+#    #+#              #
#    Updated: 2017/05/30 20:46:03 by adaly            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libft.a

FLAGS= -c -Wall -Wextra -Werror

INCLUDES= ./

SRCS1= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memrchr.c ft_memset.c ft_strcat.c \
ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
ft_strlcat.c ft_strlen.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
ft_strstr.c ft_tolower.c ft_toupper.c 

SRCS2= ft_putstr_fd.c ft_putchar_fd.c ft_putchar.c ft_putstr.c \
 ft_delimcount.c ft_delimstrlen.c ft_itoa.c \
ft_memalloc.c ft_memdel.c ft_numlen.c ft_passchr.c \
ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putnbr.c ft_putstr.c ft_putstr_fd.c ft_strclr.c \
ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c \
ft_strnew.c ft_strsplit.c ft_strsub.c ft_strtrim.c \
ft_delimcountto.c ft_putendl_fd.c ft_putnbr_fd.c 

SRCSBONUS= ft_lstmap.c ft_lstiter.c ft_lstdel.c ft_lstdelone.c \
ft_lstadd.c ft_lstnew.c 

SRCSEXTRA= ft_foreach.c ft_isthere_var.c ft_strcapitalize.c \
ft_strlcpy.c ft_strlowcase.c ft_strnchr.c ft_strupcase.c \
ft_str_is_alpha.c ft_str_is_printable.c ft_str_is_uppercase.c \
ft_str_is_numeric.c ft_str_is_lowercase.c ft_utf8width.c \
ft_putcutf8_fd.c ft_restrcat.c ft_restrccat.c ft_longlongcat.c \
ft_open_file.c ft_next_square.c ft_next_sqrt.c ft_how_many_char.c \
ft_strequ_multi.c ft_find_replace.c ft_lowercase.c ft_read_file.c \
ft_get_next_n_lines.c get_next_line.c ft_itoa_base.c ft_itoa_float.c \
ft_char_expand.c ft_utoa_base.c 

SRCSPRINTF= ft_argument_handling.c ft_evaluate.c ft_printf.c ft_float.c \
ft_import_type.c ft_flags.c ft_revised_printf.c ft_tslist.c ft_integer_types.c \
ft_floating_types.c ft_other_types.c ft_ptr.c

OBJECTS1= ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o \
ft_isascii.o ft_isdigit.o ft_isprint.o ft_memccpy.o \
ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o \
ft_memrchr.o ft_memset.o ft_strcat.o \
ft_strchr.o ft_strcmp.o ft_strcpy.o ft_strdup.o	\
ft_strlcat.o  ft_strlen.o ft_strncat.o \
ft_strncmp.o ft_strncpy.o ft_strnstr.o ft_strrchr.o \
ft_strstr.o ft_tolower.o ft_toupper.o \
ft_putstr_fd.o ft_putchar_fd.o ft_putchar.o 

OBJECTS2= ft_putstr_fd.o ft_putchar_fd.o ft_putchar.o ft_putstr.o \
 ft_delimcount.o ft_delimstrlen.o ft_itoa.o \
ft_memalloc.o ft_memdel.o ft_numlen.o ft_passchr.o \
ft_putchar.o ft_putchar_fd.o ft_putendl.o \
ft_putnbr.o	ft_putstr.o	ft_putstr_fd.o ft_strclr.o \
ft_strdel.o	ft_strequ.o	ft_striter.o ft_striteri.o \
ft_strjoin.o ft_strmap.o ft_strmapi.o ft_strnequ.o \
ft_strnew.o	ft_strsplit.o ft_strsub.o ft_strtrim.o \
ft_delimcountto.o ft_putendl_fd.o ft_putnbr_fd.o 

OBJECTSBONUS= ft_lstnew.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o \
ft_lstiter.o ft_lstmap.o 

OBJECTSEXTRA= ft_foreach.o ft_isthere_var.o ft_strcapitalize.o \
ft_strlcpy.o ft_strlowcase.o ft_strnchr.o ft_strupcase.o \
ft_str_is_alpha.o ft_str_is_printable.o ft_str_is_uppercase.o \
ft_str_is_numeric.o ft_str_is_lowercase.o ft_putcutf8_fd.o \
ft_utf8width.o ft_restrcat.o ft_restrccat.o ft_longlongcat.o \
ft_open_file.o ft_next_square.o ft_next_sqrt.o ft_how_many_char.o \
ft_strequ_multi.o ft_find_replace.o ft_lowercase.o ft_read_file.o \
ft_get_next_n_lines.o get_next_line.o ft_itoa_base.o ft_itoa_float.o \
ft_char_expand.o ft_utoa_base.o 

OBJECTSPRINTF= ft_argument_handling.o ft_evaluate.o ft_printf.o ft_float.o \
ft_import_type.o ft_flags.o ft_revised_printf.o ft_tslist.o ft_integer_types.o \
ft_floating_types.o ft_other_types.o ft_ptr.o

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -I$(INCLUDES) $(SRCS1)$(SRCS2)$(SRCSBONUS)$(SRCSEXTRA)$(SRCSPRINTF)
		ar rc $(NAME) $(OBJECTS1)$(OBJECTS2)$(OBJECTSBONUS)$(OBJECTSEXTRA)$(OBJECTSPRINTF)
		ranlib $(NAME)

clean: 
		rm -f $(OBJECTS1)$(OBJECTS2)$(OBJECTSBONUS)$(OBJECTSEXTRA)$(OBJECTSPRINTF)

fclean: clean
		rm -f $(NAME)

re: fclean all
