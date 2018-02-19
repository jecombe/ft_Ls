# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/19 15:21:11 by jecombe      #+#   ##    ##    #+#        #
#    Updated: 2018/02/19 15:24:47 by jecombe     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean

NAME = ft_ls

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

HEAD = -I

LIB_DIR = ./libft/

LIB = libft.a

FILES = ft_init.c \
		ft_create_tree.c \
		ft_check_option.c \
		ft_list.c \
		ft_print.c \
		ft_sort.c \
		main.c \

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@gcc -o $(NAME) $(OBJS) $(LIB_DIR)$)$(LIB)
	@echo "\033[1;35m ==========> COMPILING $(NAME)"
	@echo "\033[1;32m ==========[ FILLIT SUCCESSFULLY CREATED ]=========="

$(LIB):
	@cd $(LIB_DIR) && $(MAKE)

./%.o: ./%.c
	@$(CC) $(HEAD) $(CC_FLAGS) -o $@ -c $<
	@echo "\033[1;34m$@ ==> CREATED"

clean:
	@cd $(LIB_DIR) && $(MAKE) $@
	@/bin/rm -f $(OBJS)
	@echo "\033[1;31m$(OBJS) ==> DELETED"

fclean: clean
	@cd $(LIB_DIR) && /bin/rm -f $(LIB)
	@/bin/rm -f $(NAME)
	@echo "\033[1;31m$(LIB) ==> DELETED"
	@echo "\033[1;31m$(NAME) ==> DELETED"
re: fclean all
