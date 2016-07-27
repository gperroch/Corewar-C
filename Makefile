# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/14 09:17:27 by tpaulmye          #+#    #+#              #
#    Updated: 2016/05/14 15:22:21 by tpaulmye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM = asm
NAME_COREWAR = corewar

SRC_ASM_PATH = ./asm_src/
SRC_ASM_NAME = 	main.c ft_tools.c ft_save_source.c ft_print.c ft_check_line.c \
				ft_lexical_analysis.c ft_parse_header.c ft_parse_lexeme.c \
				ft_parse_param.c ft_free.c ft_create_bytecode.c \
				ft_semantic_analysis.c ft_write_bytecode.c ft_get_source.c \
				ft_tools_2.c ft_parse_option.c ft_option_debug_champion.c

SRC_COREWAR_PATH = ./corewar_src/
SRC_COREWAR_NAME = main.c load_champion.c dump_mem.c init_memory.c parsing.c \
				   ft_isnumber.c ft_double_number.c usage.c ft_tabjoin_str.c \
				   ft_tabjoin_int.c init_proc.c print_error.c int_swap.c \
				   cycles_execution.c process_execution.c op_execution.c \
				   still_alive.c inc_pc.c get_short.c get_int.c \
				   short_swap.c op_add.c op_sub.c op_zjmp.c op_aff.c op_fork.c \
				   op_lfork.c kill_process.c op_ld.c op_lld.c op_and.c \
				   op_or.c op_xor.c op_live.c get_int_from.c op_ldi.c op_lldi.c \
				   write_int.c op_st.c op_sti.c get_champ_by_nb.c modulo.c \
				   init_ncurses.c dump_mem_ncurses.c init_memory_ncurses.c \
				   write_at_ncurse.c \
				   update_ncurses.c update_pc_ncurses.c refresh_screen.c \
				   pause_menu.c get_out.c update_screen.c debug_process.c \
				   display_champ_ncurse.c get_lives_by_champ.c \
				   verification_cycle.c end_game.c

OBJ_ASM_PATH = ./obj_asm/
OBJ_COREWAR_PATH = ./obj_corewar/
INC_PATH = ./includes/ ./libft/includes
LIBFT = libft/libft.a
LIB_PATH = ./libft/
LIB_NAMES = -lft
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_ASM_NAME = $(SRC_ASM_NAME:.c=.o)
OBJ_ASM = $(addprefix $(OBJ_ASM_PATH),$(OBJ_ASM_NAME))

OBJ_COREWAR_NAME = $(SRC_COREWAR_NAME:.c=.o)
OBJ_COREWAR = $(addprefix $(OBJ_COREWAR_PATH),$(OBJ_COREWAR_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))
LDFLAGS = $(LIB) $(LIB_NAMES)

.PHONY: all clean fclean re libft

all: $(LIBFT) $(NAME_ASM) $(NAME_COREWAR)

$(NAME_ASM): $(LIBFT) $(OBJ_ASM)
	@$(CC) $^ -o $@ $(LDFLAGS)
	@echo "$(NAME_ASM) complete ! 🍻 "

$(NAME_COREWAR): $(LIBFT) $(OBJ_COREWAR)
	@$(CC) $^ -o $@ $(LDFLAGS) -lncurses
	@echo "$(NAME_COREWAR) complete ! 🍻 "

$(OBJ_ASM_PATH)%.o: $(SRC_ASM_PATH)%.c
	@mkdir $(OBJ_ASM_PATH) 2> /dev/null || echo  > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_COREWAR_PATH)%.o: $(SRC_COREWAR_PATH)%.c
	@mkdir $(OBJ_COREWAR_PATH) 2> /dev/null || echo  > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_ASM) $(OBJ_COREWAR)
	@rmdir $(OBJ_COREWAR_PATH) $(OBJ_ASM_PATH) obj 2> /dev/null || echo  > /dev/null
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME_ASM) $(NAME_COREWAR)
	@make fclean -C libft
	@echo "Everything's clean, master !"

re: fclean all

$(LIBFT):
	make -j4 -C libft noasm
