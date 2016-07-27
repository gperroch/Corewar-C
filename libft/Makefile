# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/13 17:27:04 by tpaulmye          #+#    #+#              #
#    Updated: 2016/05/14 15:32:03 by tpaulmye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME = MacOS
NAME = libft.a

# 						***directories***
INC_PATH	 = includes/
SRCC_PATH 	 = src/cfiles/
SRCS_PATH 	 = src/sfiles/
OBJ_PATH 	 = obj/
SRCL_PATH     = legacy/

# 						  ***sources***
include files.mk

# 						  ***objects***
OBJC = $(C_FILES:$(SRCC_PATH)%.c=$(OBJ_PATH)%.o)
OBJS = $(S_FILES:$(SRCS_PATH)%.s=$(OBJ_PATH)%.o)
OBJL = $(L_FILES:$(SRCL_PATH)%.c=$(OBJ_PATH)%.o)
OBJC_DIRS = $(C_DIRS:$(SRCC_PATH)%=$(OBJ_PATH)%)
OBJS_DIRS = $(S_DIRS:$(SRCS_PATH)%=$(OBJ_PATH)%)
OBJL_DIRS = obj/


# 					  ***compiler stuff***
CC 	 	= gcc
CFLAGS  = -Wall -Wextra -Werror

ifeq ($(UNAME), Linux)
	SCC = nasm
	SFLAGS = -f elf64 -p ./includes/syscall_linux.s
else
	SCC = /nfs/2014/t/tpaulmye/.brew/Cellar/nasm/2.11.08_1/bin/nasm
	SFLAGS = -f macho64 --prefix _ -p ./includes/syscall_mac.s
endif

#						***let's go***

all: $(NAME)

noasm: $(OBJC) $(OBJL)
	@ar rc $(NAME) $(OBJC) $(OBJL)
	@ranlib $(NAME)
	@echo "\n$(NAME) compilated \o/"

$(NAME): $(OBJC) $(OBJS)
	@ar rc $(NAME) $(OBJC) $(OBJS)
	@ranlib $(NAME)
	@echo "\n$(NAME) compilated \o/"

$(OBJC): $(OBJ_PATH)%.o : $(SRCC_PATH)%.c
	@mkdir -p $(OBJC_DIRS) $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@ \
	&& printf "."

$(OBJS): $(OBJ_PATH)%.o : $(SRCS_PATH)%.s
	@mkdir -p $(OBJS_DIRS) $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(SCC) $(SFLAGS) -I $(INC_PATH) $< -o $@  \
			&& printf "."

$(OBJL): $(OBJ_PATH)%.o : legacy/%.c
	@mkdir -p $(OBJL_DIRS) $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@ \
	&& printf "."

clean:
	@rm $(OBJC) $(OBJS) 2> /dev/null || echo "" > /dev/null
	@rm -rf $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re:
	make fclean
	make all
