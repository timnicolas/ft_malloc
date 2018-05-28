# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 13:52:33 by tnicolas          #+#    #+#              #
#    Updated: 2018/05/24 13:52:33 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
NAME_LINK = libft_malloc.so

FILES = malloc.c \
		realloc.c \
		free.c \
		show_alloc_mem.c \
		alloc_memory.c

HFILES = includes/ft_malloc.h \
		 includes/ft_malloc.h \
		 libft/includes/libft.h

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
LIBFT_LIB = -L $(LIBFT_DIR) -lft

CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -g3 #-Werror

OBJS_DIR = objs/
SRCS_DIR = srcs/

INC_DIR =	includes/ \
			$(LIBFT_DIR)includes/

INC := $(addprefix -I , $(INC_DIR))
SRCS := $(addprefix $(SRCS_DIR), $(FILES))
OBJS := $(addprefix $(OBJS_DIR), $(FILES:.c=.o))

NORMAL = "\x1B[0m"
RED = "\x1B[31m"
GREEN = "\x1B[32m"
YELLOW = "\x1B[33m"
BLUE = "\x1B[34m"
MAGENTA = "\x1B[35m"
CYAN = "\x1B[36m"
WHITE = "\x1B[37m"
BOLD = "\e[1m"
LIGHT = "\e[2m"
ITALIC = "\e[3m"
ULINE = "\e[4m"

START = @printf $(GREEN)$(BOLD)"FT_MALLOC\n--------------------\n"$(NORMAL)
END = @printf $(GREEN)$(BOLD)"--------------------\n"$(NORMAL)

all:
	@make -C $(LIBFT_DIR)
	$(START)
	@make $(NAME)
	$(END)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT)
	@printf $(CYAN)"-> create lib : $(NAME)\n"$(NORMAL)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf $(CYAN)"-> create link : $(NAME_LINK)\n"$(NORMAL)
	@rm -rf $(NAME_LINK)
	@ln -s $(NAME) $(NAME_LINK)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HFILES)
	@printf $(YELLOW)"-> $<\n"$(NORMAL)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))

clean:
	@make -C $(LIBFT_DIR) clean
	$(START)
	@printf $(RED)"-x remove .o files\n"$(NORMAL)
	@rm -rf $(OBJS_DIR)
	$(END)

fclean: clean
	@make -C $(LIBFT_DIR) cleanlib
	$(START)
	@printf $(RED)"-x remove $(NAME)\n"$(NORMAL)
	@printf $(RED)"-x remove $(NAME_LINK)\n"$(NORMAL)
	@rm -f $(NAME) $(NAME_LINK)
	$(END)

re: fclean
	@make

exec:
	@clear
	@make
	$(START)
	@printf $(YELLOW)"->create test program\n"$(EOC)
	@$(CC) test/main.c $(INC) $(CFLAGS) $(LIBFT_LIB) $(NAME)
	$(END)
	@printf $(MAGENTA)$(BOLD)"EXEC FT_MALLOC\n--------------------\n"$(NORMAL)
	@./a.out
	@rm a.out
	@printf $(MAGENTA)$(BOLD)"--------------------\n"$(NORMAL)

reexec: re exec

.PHONY: all clean fclean re exec reexec
