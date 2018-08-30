# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 11:03:22 by kmayika           #+#    #+#              #
#    Updated: 2018/08/28 13:35:53 by kmayika          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a 
GCFLAGS	= -Wall -Wextra -Werror 
CC	= gcc 
SRCSF	= ft_isdigit.c\
	  ft_isascii.c\
	  ft_isspace.c\
	  ft_strdup.c\
	  ft_islower.c\
	  ft_isupper.c\
	  ft_isalpha.c\
	  ft_isalnum.c\
	  ft_isprint.c\
	  ft_strlen.c\
	  ft_strncpy.c\
	  ft_strcpy.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_memset.c\
	  ft_memcpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memmove.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_bzero.c\
	  ft_strcat.c\
	  ft_strlcat.c\
	  ft_strdel.c\
	  ft_strnstr.c\
	  ft_strclr.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strjoin.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_strmapi.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strncat.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_strstr.c\
	  ft_atoi.c\
	  ft_itoa.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  get_next_line.c

OBJ = $(SRCSF:%.c=%.o)


all: $(NAME)

$(NAME):
	$(CC) $(GCFLAGS) -c $(SRCSF)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) 
fclean: clean
	rm -f $(NAME)
re:	fclean all 
