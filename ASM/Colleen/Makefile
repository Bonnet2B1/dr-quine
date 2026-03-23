# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 12:00:00 by edelarbr          #+#    #+#              #
#    Updated: 2026/03/23 15:36:28 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	Colleen

# ------------------------------ Sources -----------------------------

SRCS		:=	Colleen.s

OBJ_DIR		:=	.objs
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.s=.o))

# ------------------------------ Flags -------------------------------

ifeq ($(shell uname -s), Darwin)
	FORMAT := macho64
else
	FORMAT := elf64
endif

NASM		:=	nasm
NASMFLAGS	:=	-f $(FORMAT)
CC			:=	gcc
RM			:=	rm -rf
SHELL		:=	/bin/bash

$(OBJ_DIR)/%.o : %.s
				@ mkdir -p $(dir $@)
				@ $(NASM) $(NASMFLAGS) $< -o $@

# ------------------------------ Colors ------------------------------

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ Compilation -------------------------

all:			$(NAME)

$(NAME):		$(OBJS)
				@ echo -e "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) -o $(NAME) $(OBJS)
				@ echo -e "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

# -------------------------------- Rules -----------------------------

clean:
				@ $(RM) $(OBJ_DIR)
				@ echo -e "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME)
				@ echo -e "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

test:			$(NAME)
				@ echo -e "$(CYAN)Testing $(NAME)...$(CLR_RMV)"
				@ ./$(NAME) > tmp_$(NAME)
				@ diff tmp_$(NAME) $(SRCS) && echo -e "$(GREEN)Test passed! (No differences)$(CLR_RMV)" || (echo -e "$(RED)Test failed! (Differences found)$(CLR_RMV)" && exit 1)
				@ rm -f tmp_$(NAME)

.PHONY:			all clean fclean re test
