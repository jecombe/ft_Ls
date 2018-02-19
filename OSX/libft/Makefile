# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecombe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:30 by jecombe           #+#    #+#              #
#    Updated: 2017/12/12 18:25:28 by jecombe     ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

OPTION = -c -I $(HEAD)

CC_FLAG = -Werror -Wextra -Wall

FILES = ft_islower.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strmapi.c \
	  ft_strsplit.c ft_isprint.c ft_memdel.c ft_putstr.c ft_strequ.c \
	  ft_strncat.c ft_strstr.c ft_atoi.c ft_isspace.c ft_memmove.c \
	  ft_putstr_fd.c ft_striter.c ft_strncmp.c ft_strsub.c ft_bzero.c \
	  ft_isupper.c ft_memset.c ft_strcat.c ft_striteri.c ft_strncpy.c \
	  ft_strtrim.c ft_count_word.c ft_itoa.c ft_putchar.c ft_strchr.c \
	  ft_strjoin.c ft_strnequ.c ft_tolower.c ft_isalnum.c ft_memalloc.c \
	  ft_putchar_fd.c ft_strclr.c ft_strlcat.c ft_strnew.c ft_toupper.c \
	  ft_isalpha.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strlen.c \
	  ft_strnlen.c  ft_isascii.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c \
	  ft_strlen_split.c ft_strnstr.c ft_isdigit.c ft_memcmp.c ft_putnbr.c \
	  ft_strdel.c ft_strmap.c ft_strrchr.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstnew.c ft_swap.c ft_lstmap.c

SRCS = $(FILES)

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@echo "\033[1;32m ==========[ LIBFT SUCCESSFULLY CREATES ]=========="
	@ar rcs $(NAME) $(OBJS)

./%.o : ./%.c
	@$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo "\033[1;34m$@ ==> CREATED"

clean:
	@/bin/rm -f $(OBJS)
	@echo "\033[1;31m$(OBJS) ==> DELETED"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;31m$(NAME) ==> DELETED"

re: fclean all

.PHONY : clean fclean all re
