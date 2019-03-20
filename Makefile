# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 13:52:33 by tnicolas          #+#    #+#              #
#    Updated: 2019/03/20 17:58:21 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
NAME_LINK = libft_malloc.so

FILES = libft/srcs/ft_strlen.c \
		libft/srcs/ft_putchar.c \
		libft/srcs/ft_putstr.c \
		libft/srcs/ft_putendl.c \
		libft/srcs/ft_putnbr.c \
		libft/srcs/ft_putchar_fd.c \
		libft/srcs/ft_putstr_fd.c \
		libft/srcs/ft_putendl_fd.c \
		libft/srcs/ft_putnbr_fd.c \
		libft/srcs/ft_strcmp.c \
		libft/srcs/ft_strncmp.c \
		libft/srcs/ft_strcpy.c \
		libft/srcs/ft_strncpy.c \
		libft/srcs/ft_strcat.c \
		libft/srcs/ft_strncat.c \
		libft/srcs/ft_toupper.c \
		libft/srcs/ft_tolower.c \
		libft/srcs/ft_isalpha.c \
		libft/srcs/ft_isdigit.c \
		libft/srcs/ft_isalnum.c \
		libft/srcs/ft_isascii.c \
		libft/srcs/ft_isprint.c \
		libft/srcs/ft_atoi.c \
		libft/srcs/ft_itoa.c \
		libft/srcs/ft_strstr.c \
		libft/srcs/ft_strnstr.c \
		libft/srcs/ft_strchr.c \
		libft/srcs/ft_strrchr.c \
		libft/srcs/ft_memalloc.c \
		libft/srcs/ft_memdel.c \
		libft/srcs/ft_strnew.c \
		libft/srcs/ft_strdel.c \
		libft/srcs/ft_strclr.c \
		libft/srcs/ft_striter.c \
		libft/srcs/ft_striteri.c \
		libft/srcs/ft_strmap.c \
		libft/srcs/ft_strmapi.c \
		libft/srcs/ft_strequ.c \
		libft/srcs/ft_strnequ.c \
		libft/srcs/ft_strsub.c \
		libft/srcs/ft_strjoin.c \
		libft/srcs/ft_strtrim.c \
		libft/srcs/ft_strsplit.c \
		libft/srcs/ft_strdup.c \
		libft/srcs/ft_memset.c \
		libft/srcs/ft_bzero.c \
		libft/srcs/ft_memcpy.c \
		libft/srcs/ft_memccpy.c \
		libft/srcs/ft_memmove.c \
		libft/srcs/ft_memchr.c \
		libft/srcs/ft_memcmp.c \
		libft/srcs/ft_strlcat.c \
		libft/srcs/list/ft_lstnew.c \
		libft/srcs/list/ft_lstdelone.c \
		libft/srcs/list/ft_lstdel.c \
		libft/srcs/list/ft_lstadd.c \
		libft/srcs/list/ft_lstiter.c \
		libft/srcs/list/ft_lstmap.c \
		libft/srcs/list/ft_lstget.c \
		libft/srcs/bonus/ft_intlen.c \
		libft/srcs/bonus/ft_atol.c \
		libft/srcs/bonus/ft_max.c \
		libft/srcs/bonus/ft_min.c \
		libft/srcs/bonus/ft_realloc.c \
		libft/srcs/bonus/ft_read_fd.c \
		libft/srcs/bonus/ft_read_file.c \
		libft/srcs/bonus/ft_int_to_base.c \
		libft/srcs/bonus/ft_int_to_nbase.c \
		libft/srcs/bonus/ft_base_to_int.c \
		libft/srcs/bonus/ft_convert_base.c \
		libft/srcs/bonus/ft_atoi_base.c \
		libft/srcs/bonus/ft_ftoa.c \
		libft/srcs/bonus/ft_ltoa.c \
		libft/srcs/bonus/ft_lltoa.c \
		libft/srcs/bonus/ft_abs.c \
		libft/srcs/bonus/ft_free.c \
		libft/srcs/bonus/ft_fruit.c \
		libft/srcs/bonus/ft_free_tab.c \
		libft/srcs/bonus/ft_fruit_tab.c \
		libft/srcs/bonus/ft_strndup.c \
		libft/srcs/bonus/ft_power.c \
		libft/srcs/bonus/ft_2arg.c \
		libft/srcs/bonus/ft_get2arg.c \
		libft/srcs/bonus/ft_islower.c \
		libft/srcs/bonus/ft_isupper.c \
		libft/srcs/bonus/ft_isspace.c\
		libft/srcs/bonus/ft_swap_int.c \
		libft/srcs/bonus/ft_clean_char.c \
		libft/srcs/bonus/ft_test_malloc.c \
		libft/srcs/bonus/get_next_line.c \
		libft/srcs/ft_printf/printf/ft_printf.c \
		libft/srcs/ft_printf/printf/ft_vprintf.c \
		libft/srcs/ft_printf/printf/ft_errprintf.c \
		libft/srcs/ft_printf/printf/ft_verrprintf.c \
		libft/srcs/ft_printf/printf/ft_dprintf.c \
		libft/srcs/ft_printf/printf/ft_vdprintf.c \
		libft/srcs/ft_printf/printf/ft_asprintf.c \
		libft/srcs/ft_printf/printf/ft_vasprintf.c \
		libft/srcs/ft_printf/printf/ft_joinprintf.c \
		libft/srcs/ft_printf/printf/ft_joinnprintf.c \
		libft/srcs/ft_printf/color/ft_color.c \
		libft/srcs/ft_printf/color/ft_init_color.c \
		libft/srcs/ft_printf/check/ft_parse.c \
		libft/srcs/ft_printf/check/ft_check.c \
		libft/srcs/ft_printf/check/ft_initarg.c \
		libft/srcs/ft_printf/check/ft_forest.c \
		libft/srcs/ft_printf/check/ft_checkconv.c \
		libft/srcs/ft_printf/check/ft_check_error_flag.c \
		libft/srcs/ft_printf/check/ft_cleanstars.c \
		libft/srcs/ft_printf/check/ft_cleanstars_2.c \
		libft/srcs/ft_printf/ft_strfreejoin.c \
		libft/srcs/ft_printf/conv/ft_wchart.c \
		libft/srcs/ft_printf/conv/ft_wchart_2.c \
		libft/srcs/ft_printf/conv/ft_getheight.c \
		libft/srcs/ft_printf/conv/ft_precision_e.c \
		libft/srcs/ft_printf/conv/ft_precision_e_2.c \
		libft/srcs/ft_printf/conv/ft_conv_bigs.c \
		libft/srcs/ft_printf/conv/ft_conv_bigs_2.c \
		libft/srcs/ft_printf/conv/ft_conv_s.c \
		libft/srcs/ft_printf/conv/ft_fill_str_ud.c \
		libft/srcs/ft_printf/conv/ft_conv_d.c \
		libft/srcs/ft_printf/conv/ft_conv_o.c \
		libft/srcs/ft_printf/conv/ft_conv_u.c \
		libft/srcs/ft_printf/conv/ft_conv_x.c \
		libft/srcs/ft_printf/conv/ft_conv_c.c \
		libft/srcs/ft_printf/conv/ft_conv_k.c \
		libft/srcs/ft_printf/conv/ft_conv_n.c \
		libft/srcs/ft_printf/conv/ft_conv_b.c \
		libft/srcs/ft_printf/conv/ft_conv_w.c \
		libft/srcs/ft_printf/conv/ft_conv_f.c \
		libft/srcs/ft_printf/conv/ft_flags_f.c \
		libft/srcs/ft_printf/conv/ft_arrondis_f.c \
		libft/srcs/ft_printf/conv/ft_conv_e.c \
		libft/srcs/ft_printf/conv/ft_conv_g.c \
		libft/srcs/ft_printf/conv/ft_conv_g_annexe.c \
		libft/srcs/ft_printf/conv/ft_conv_r.c \
		libft/srcs/ft_printf/conv/ft_conv_modulo.c \
		libft/srcs/ft_printf/conv/ft_conv_invalid.c \
		libft/srcs/ft_printf/conv/ft_regle_de_merde.c \
		srcs/malloc.c \
		srcs/realloc.c \
		srcs/calloc.c \
		srcs/free.c \
		srcs/free_all.c \
		srcs/show_alloc_mem.c \
		srcs/alloc_memory.c \
		srcs/alloc_memory_2.c \
		srcs/get_alloc_size.c \
		srcs/print_alloc_mem.c \
		srcs/is_allocated.c


HFILES = includes/ft_malloc.h \
		 libft/includes/libft.h \
		 libft/includes/struct.h \
		 libft/includes/ft_printf.h \
		 libft/includes/ft_printf_struct.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs/
SRCS_DIR = srcs/

INC_DIR =	includes/ \
			libft/includes/

INC := $(addprefix -I , $(INC_DIR))
SRCS := $(FILES)
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
	$(START)
	@make $(NAME)
	$(END)

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@printf $(CYAN)"-> create link : $(NAME_LINK)\n"$(NORMAL)
	@rm -rf $(NAME_LINK)
	@ln -s $(NAME) $(NAME_LINK)

$(OBJS_DIR)%.o: %.c $(HFILES)
	@printf $(YELLOW)"-> $<\n"$(NORMAL)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))

clean:
#	@make -C $(LIBFT_DIR) clean
	$(START)
	@printf $(RED)"-x remove .o files\n"$(NORMAL)
	@rm -rf $(OBJS_DIR)
	$(END)

fclean: clean
#	@make -C $(LIBFT_DIR) cleanlib
	$(START)
	@printf $(RED)"-x remove $(NAME)\n"$(NORMAL)
	@printf $(RED)"-x remove $(NAME_LINK)\n"$(NORMAL)
	@rm -rf $(NAME) $(NAME_LINK) a.out.dSYM a.out
	$(END)

re: fclean
	@make

exec:
	@clear
	@make
	$(START)
	@printf $(YELLOW)"->create test program\n"$(NORMAL)
	@$(CC) test/main.c $(INC) $(CFLAGS) $(NAME)
	$(END)
	@printf $(MAGENTA)$(BOLD)"EXEC FT_MALLOC\n--------------------\n"$(NORMAL)
	@./a.out
	@rm a.out
	@printf $(MAGENTA)$(BOLD)"--------------------\n"$(NORMAL)

reexec: fclean exec

valg:
	@clear
	@make CFLAGS="-Wall -Wextra -g3"
	$(START)
	@printf $(YELLOW)"->create test program\n"$(NORMAL)
	@$(CC) test/main.c $(INC) -Wall -Wextra -g3 $(NAME)
	$(END)

revalg: fclean valg

.PHONY: all clean fclean re exec reexec
