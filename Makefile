# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 11:27:45 by jflorido          #+#    #+#              #
#    Updated: 2023/08/07 11:47:55 by jflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#ANSI Shadow
define HEADER

██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗
██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝
██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗
██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║
██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║
╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝


@@@@@@@@@@@@&BP5YYY5G#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@B5J???JJJ??J5B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@5??JJJJJJJJJJ??JY5PB#&@@@@@@&&&#BGBB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@P?JJJJJJJJJJJJJJJ????JJYY55YYJJJJ????JYG&@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@B?JJJJJJJJJJJJJJJJJJJJJJJ????JJJJJJJJJJ??J5G#@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@G??JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ??J5#@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@BGJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?J5B@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@#GJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ??YG&@@@@@@@@@@@@@@@@
@@@@@@@@@@@@BJ?JJJJJJJJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ??JG@@@@@@@@@@@@@@@
@@@@@@@@@@@@@&BYJJJJJJYB@#YJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?Y#@@@@@@@@@@@@@
@@@@@@@@@@@@@@PJJJJJJJ5#BJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?J#@@@@@@@@@@@@
@@@@@@@@@@@@&Y?JJJJJ?????JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?J&@@@@@@@@@@@
@@@@@@@@@@@@5?JJJJJY5PBY?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?Y&@@@@@@@@@@
@@@@@@@@@@@&J?JJJJJ&@@@B?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?JB@@@@@@@@@
@@@@@@@@@@@@#5?JJJJYG&@@5?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?JG@@@@@@@@
@@@@@@@@@@@@@@BJ?JJJ?JP&G?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?B@@@@@@@
@@@@@@@@@@@@@@@#Y?JJJJ?JYJJJJJJJJJJJJJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJ?J&@@@@@@
@@@@@@@@@@@@@@@@#J?JJJJJJJJJJJJJJJJJJJGJ?JJJJJJJJJJJJJJJJJJJJJJJJJJ?P@@@@@@
@@@@@@@@@@@@@@@@@&Y?JJJJJJJJJJJJJJJJ?G@&PYJ??JJJJJJJJJJJJJJJJJJJJJJJJ&@@@@@
@@@@@@@@@@@@@@@@@@@PJJJJJJJJJJJJJJJJJ&@@@&#PYJJJJJJJJJJJJJJJJJJJJJJJ?5@@@@@
@@@@@@@@@@@@@@@@#G5YJJJJJJJJJJJJJJJJJYYYYYY55YJJJJJJJJJJJJJJJJJJJJJJJ?G@@@@
@@@@@@@@@@@@@#PYJ??JJJJJJJJJJJJJJJJJJJJJJ????JJJJJJJJJJJJJJJJJJJJJJJJ?5@@@@
@@@@@@@@@@@&5J?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?Y@@@@
@@@@@@@@@@&Y?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?P@@@@
@@@@@@@@@@5?JJJJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ?B@@@@
@@@@@@@@@G?JJJ?JPJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJY@@@@@
@@@@@@@@@G?JJ?5#GJJJJJJJJJJJJJJJJJJJJJ????JJJJJJJJJJJJJJJJJJJJJJJJJJ?5&&&&&
@@@@@@@@@@P???5Y?JJJJJJJJJJJJJJJJJJJJJ5P5YJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@BP5YJJJJJJJJJJJJJJJJJJJJJJJJG@BJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@BJ?JJJJJJJJJJJJJJJJJJJJ?5GJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@#Y??JJJJJJJJJJJJJJJJJJJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@G5J?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@&5??JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@B5J?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@#PJ??JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@&B5J??JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B5J?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&PJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&PJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#5JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5J?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@PJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@GJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ


endef
export HEADER

# Folders
SRC_DIR = src/
OBJ_DIR = obj/
#LIBFT_DIR = libft/

OBJF = obj
INC = inc

# Files
SRC_FILES = philo \
			utils \
			checks inits \
			philo_utils \
			watcher
#SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#Commands
CC 			= 	gcc
SANI 		= 	-g3 -fsanitize=address
CFLAGS 		= 	-g -Wall -Wextra -Werror -pthread
RM 			= 	rm -rf

#LIBFT_a 	= 	libft/libft.a

#Colors:
DEF_COLOR 	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;31m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# ====================================================================== #

all: $(NAME)

# Compiling all
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INC) -o $(NAME)
	@echo "$(GREEN)$$HEADER$(DEF_COLOR)"
	@echo "$(GREEN)Philosophers compiled!$(DEF_COLOR)"

# Compiling individual
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(BLUE)Compiling $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

# Crear directorio temporal para los obj
$(OBJF):
	@mkdir -p $(OBJ_DIR)

# Cleanning files
clean:
	$(RM) $(OBJS)
	@echo "$(YELLOW)&(OBJS) --> Files removed.$(DEF_COLOR)"

#Cleanning files and executable
fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)$(NAME) Executable files removed!$(DEF_COLOR)"

re: fclean all

normi:
	@norminette $(SRC_DIR) $(INC)

sani: fclean
	$(MAKE) CFLAGS='$(CFLAGS) $(SANI)' all

.PHONY: all clean fclean re
