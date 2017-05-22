#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaury <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:00:31 by fmaury            #+#    #+#              #
#    Updated: 2017/05/13 14:30:42 by fmaury           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= asm

COMPILER		= gcc

CC_FLAGS		= -Wall -Werror -Wextra -g

INC				= ./includes/asm.h \
					./includes/op.h

SRC_DIR			= ./srcs

SRC				=	main.c \
					ft_head.c \
					ft_launcher.c

OBJ				= $(SRC:.c=.o)

SRCS			= $(addprefix $(SRC_DIR)/, $(SRC))

NEWLINE			= @echo ""

all : $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(NEWLINE)
	@echo "Compilation de la libft..."
	@MAKE -C libft/
	@$(NEWLINE)
	@echo "Compilation de l'asm..."
	@$(COMPILER) $(CC_FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)
	@$(NEWLINE)
	@echo "asm cree !"
	$(NEWLINE)

%.o: $(SRC_DIR)/%.c
	@$(COMPILER) $(CC_FLAGS) -I includes -c $< -o $@

clean:
	@echo "Suppression des objets"
	$(NEWLINE)
	@MAKE clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@echo "Suppression de l'executable"
	$(NEWLINE)
	@MAKE fclean -C libft/
	@rm -rf $(NAME)

re: fclean 
	@$(MAKE) all

.PHONY: all clean fclean re
