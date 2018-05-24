# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:45:36 by tnicolas          #+#    #+#              #
#    Updated: 2018/02/19 16:01:29 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_strlen.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_strdup.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcat.c \
		list/ft_lstnew.c \
		list/ft_lstdelone.c \
		list/ft_lstdel.c \
		list/ft_lstadd.c \
		list/ft_lstiter.c \
		list/ft_lstmap.c \
		list/ft_lstget.c \
		bonus/ft_intlen.c \
		bonus/ft_atol.c \
		bonus/ft_max.c \
		bonus/ft_min.c \
		bonus/ft_realloc.c \
		bonus/ft_read_fd.c \
		bonus/ft_read_file.c \
		bonus/ft_int_to_base.c \
		bonus/ft_int_to_nbase.c \
		bonus/ft_base_to_int.c \
		bonus/ft_convert_base.c \
		bonus/ft_atoi_base.c \
		bonus/ft_ftoa.c \
		bonus/ft_ltoa.c \
		bonus/ft_lltoa.c \
		bonus/ft_abs.c \
		bonus/ft_free.c \
		bonus/ft_fruit.c \
		bonus/ft_free_tab.c \
		bonus/ft_fruit_tab.c \
		bonus/ft_strndup.c \
		bonus/ft_power.c \
		bonus/ft_2arg.c \
		bonus/ft_get2arg.c \
		bonus/ft_islower.c \
		bonus/ft_isupper.c \
		bonus/ft_isspace.c\
		bonus/ft_swap_int.c \
		bonus/ft_clean_char.c \
		bonus/ft_test_malloc.c \
		bonus/get_next_line.c \
		$(addprefix ft_printf/, $(FILES_FT_PRINTF))

FILES_FT_PRINTF = printf/ft_printf.c \
		printf/ft_vprintf.c \
		printf/ft_errprintf.c \
		printf/ft_verrprintf.c \
		printf/ft_dprintf.c \
		printf/ft_vdprintf.c \
		printf/ft_asprintf.c \
		printf/ft_vasprintf.c \
		printf/ft_joinprintf.c \
		printf/ft_joinnprintf.c \
		color/ft_color.c \
		color/ft_init_color.c \
		check/ft_parse.c \
		check/ft_check.c \
		check/ft_initarg.c \
		check/ft_forest.c \
		check/ft_checkconv.c \
		check/ft_check_error_flag.c \
		check/ft_cleanstars.c \
		check/ft_cleanstars_2.c \
		ft_strfreejoin.c \
		conv/ft_wchart.c \
		conv/ft_wchart_2.c \
		conv/ft_getheight.c \
		conv/ft_precision_e.c \
		conv/ft_precision_e_2.c \
		conv/ft_conv_bigs.c \
		conv/ft_conv_bigs_2.c \
		conv/ft_conv_s.c \
		conv/ft_fill_str_ud.c \
		conv/ft_conv_d.c \
		conv/ft_conv_o.c \
		conv/ft_conv_u.c \
		conv/ft_conv_x.c \
		conv/ft_conv_c.c \
		conv/ft_conv_k.c \
		conv/ft_conv_n.c \
		conv/ft_conv_b.c \
		conv/ft_conv_w.c \
		conv/ft_conv_f.c \
		conv/ft_flags_f.c \
		conv/ft_arrondis_f.c \
		conv/ft_conv_e.c \
		conv/ft_conv_g.c \
		conv/ft_conv_g_annexe.c \
		conv/ft_conv_r.c \
		conv/ft_conv_modulo.c \
		conv/ft_conv_invalid.c \
		conv/ft_regle_de_merde.c \

HFILES = includes/libft.h \
		 includes/struct.h \
		 includes/ft_printf.h \
		 includes/ft_printf_struct.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = includes/ \
		  includes/ft_printf
SRCS_DIR = srcs/
OBJ_DIR = objs/

INC := $(addprefix -I , $(INC_DIR))
SRCS := $(addprefix $(SRCS_DIR), $(FILES))
OBJ := $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

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

START = @printf $(GREEN)$(BOLD)"LIBFT\n--------------------\n"$(NORMAL)
END = @printf $(GREEN)$(BOLD)"--------------------\n"$(NORMAL)

all:
	$(START)
	@make $(NAME)
	$(END)

$(NAME): $(OBJ_DIR) $(OBJ)
	@printf $(CYAN)"-> create lib : $(NAME)\n"$(NORMAL)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HFILES)
	@printf $(YELLOW)"-> $<\n"$(NORMAL)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(dir $(OBJ))

clean:
	$(START)
	@printf $(RED)"-x remove .o files\n"$(NORMAL)
	@rm -rf $(OBJ_DIR)
	$(END)

cleanlib:
	$(START)
	@printf $(RED)"-x remove $(NAME)\n"$(NORMAL)
	@rm -f $(NAME)
	$(END)

fclean: clean
	$(START)
	@printf $(RED)"-x remove $(NAME)\n"$(NORMAL)
	@rm -rf $(NAME)
	$(END)

re: fclean
	@make

open:
	@vim +Line $(SRCS) $(HFILES) Makefile

norm:
	@printf $(BLUE)$(BOLD)"NORME LIBFT\n--------------------\n"$(NORMAL)
	@norminette $(SRCS) $(HFILES)
	@printf $(BLUE)$(BOLD)"--------------------\n"$(NORMAL)

.PHONY: all clean fclean re open norm
