# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/19 15:21:11 by jecombe      #+#   ##    ##    #+#        #
#    Updated: 2018/03/07 16:23:44 by jecombe     ###    #+. /#+    ###.fr      #
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
		ft_print_next.c \
		ft_list.c \
		ft_tools.c \
		ft_print.c \
		ft_sort.c \
		main.c \

END=\x1b[0m
BOLD=\x1b[1m
UNDER=\x1b[4m
REV=\x1b[7m

GREY=\x1b[30m
RED=\x1b[31m
GREEN=\x1b[32m
YELLOW=\x1b[33m
BLUE=\x1b[34m
PURPLE=\x1b[35m
CYAN=\x1b[36m
WHITE=\x1b[37m


BGREY=\x1b[40m
BRED=\x1b[41m
BGREEN=\x1b[42m
BYELLOW=\x1b[43mm
BBLUE=\x1b[44m
BCYAN=\x1b[46m
BPURPLE=\x1b[45m
BWHITE=\x1b[47m


ASCII_ART=\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysdyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooodddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooodddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyooooooodddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooodddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooodddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyooooooooooooooddddddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooooodddddddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooooooddddddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooooooodddddddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooooooooddddddddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyooooooooooooooooooooddddddddddddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooooooooosymmmddddddddddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyysoooooooooooooooosyhdddNNNNmmmdddddddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyysoooooooooooosyyhdddddddNNNNNNNNmmmddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyysooooooooosyhddddddddddddNNNNNNNNNNNNmmmmddddddddhyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyooooooosyhddddddddddddddddNNNNNNNNNNNNNNNNNmmmdddddhyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyysoooosyhddddddddddddddddddddNNNNNNNNNNNNNNNNNNNNNmmmdddyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyysyhdddddddddddddddddddddddddNNNNNNNNNNNNNNNNNNNNNNNNNmmdyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyhhddddddddddddddddddddddddddNNNNNNNNNNNNNNNNNNNNNNNNNmdhyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyhdddddddddddddddddddddddNNNNNNNNNNNNNNNNNNNNNNmdhyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyysyyyyyyhddddddddddddddddddddNNNNNNNNNNNNNNNNNNNmdyyyyyyhyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyysoossyyyyyhhddddddddddddddddNNNNNNNNNNNNNNNmdhyyyyyyhddhyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyysoooossyyyyyyhdddddddddddddNNNNNNNNNNNNmdhyyyyyyhddddyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyysooooosssyyyyyhhdddddddddNNNNNNNNNmdyyyyyyhddddddhyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyysoooooooossyyyyyhhddddddNNNNNmmhyyyyyyhddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyoooooooooossyyyyyyhdddNNmdhyyyyyyhddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyysoooooooooooossyyyyyhdyyyyyyhddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysoooooooooooooossyyyyyyyhddddddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooooossyhdddddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooooooddddddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyssoooooooooooooodddddddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooodddddddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooooooddddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyooooooooooodddddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooodddddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooooddddddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooooddddddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooooodddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysoooddddyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysooddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysdyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\
			$(GREY)				$(END)$(GREEN)yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy$(END)\n\




OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@gcc -o $(NAME) $(OBJS) $(LIB_DIR)$)$(LIB)
	@echo "\033[1;35m ==========> COMPILING $(NAME)"
	@echo "\033[1;32m ==========[ FT_LS SUCCESSFULLY CREATED ]=========="
	@printf "$(ASCII_ART)"

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
