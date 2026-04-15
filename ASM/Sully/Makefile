# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 16:59:43 by edelarbr          #+#    #+#              #
#    Updated: 2026/04/15 16:40:15 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	Sully

# ------------------------------ Sources -----------------------------

SRCS		:=	Sully.s

OBJ_DIR		:=	.objs
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.s=.o))

# ------------------------------ Flags -------------------------------

NASM		:=	nasm
NASM_FLAGS	:=	-f elf64
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -no-pie
RM			:=	rm -rf

$(OBJ_DIR)/%.o :%.s
    @ mkdir -p $(dir $@)
    @ $(NASM) $(NASM_FLAGS) $< -o $@

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
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(OBJS)
				@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

# -------------------------------- Rules -----------------------------

clean:
				@ $(RM) $(OBJ_DIR) Sully_0.s Sully_1.s Sully_2.s Sully_3.s Sully_4.s Sully_5.s Sully_0 Sully_1 Sully_2 Sully_3 Sully_4 Sully_5
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

test:			$(NAME)
				@ echo "$(CYAN)Testing $(NAME)...$(CLR_RMV)"
				@ ./$(NAME)
				@ echo "$(YELLOW)Diff between $(SRCS) and Sully_0.s:$(CLR_RMV)"
				@ diff $(SRCS) Sully_0.s || true
				@ echo "$(YELLOW)Diff between Sully_3.s and Sully_2.s:$(CLR_RMV)"
				@ diff Sully_3.s Sully_2.s || true
				@ echo "$(GREEN)Test finished!$(CLR_RMV)"

.PHONY:			all check clean fclean re test
