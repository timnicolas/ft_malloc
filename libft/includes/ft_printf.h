/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:15:52 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/05 18:58:47 by ynacache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <ft_printf_struct.h>
# include <ft_printf.h>

# define SUCCESS 0
# define ERROR -1
# define END 1

# include <libft.h>
# include <wchar.h>

# define PRINTF_ERROR -1

# define EOC	"\x1B[0m"

# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

# define F_RED  "\x1B[41m"
# define F_GREEN  "\x1B[42m"
# define F_YELLOW	"\x1B[43m"
# define F_BLUE  "\x1B[44m"
# define F_MAGENTA  "\x1B[45m"
# define F_CYAN  "\x1B[46m"
# define F_WHITE  "\x1B[47m"

# define CLEAR "\033[H\033[2J"

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list ap);
int			ft_asprintf(char **str, const char *format, ...);
int			ft_vasprintf(char **ret, const char *format, va_list ap);

int			ft_conv_s(char **ret, t_arg *arg);
int			ft_conv_p(char **ret, t_arg *arg);
int			ft_conv_d(char **ret, t_arg *arg);
int			ft_conv_o(char **ret, t_arg *arg);
int			ft_conv_u(char **ret, t_arg *arg);
int			ft_conv_x(char **ret, t_arg *arg);
int			ft_conv_c(char **ret, t_arg *arg);
int			ft_conv_k(char **ret, t_arg *arg);
int			ft_conv_n(char **ret, t_arg *arg);
int			ft_conv_b(char **ret, t_arg *arg);
int			ft_conv_w(char **ret, t_arg *arg, int size, int size_exposant);
int			ft_conv_f(char **ret, t_arg *arg);
int			ft_conv_e(char **ret, t_arg *arg);
int			ft_conv_g(char **ret, t_arg *arg);
int			ft_conv_r(char **ret, t_arg *arg, va_list ap);
int			ft_conv_modulo(char **ret, t_arg *arg);
int			ft_conv_invalid(char **ret, t_arg *arg);

int			ft_calcul_zero_ap(t_arg *arg);
int			calcul_exposant(t_arg *arg);
void		ft_flag_zero_neg_e(char *s, char *n, t_arg *arg);
void		ft_flag_space_plus_e(char *s, char *n, t_arg *arg);
int			ft_flags_e(char **nr, char *nn, t_arg *arg);
char		*ft_fill_rest_e(char *cpy, int exposant, int precision, t_arg *arg);
void		ft_deplace(char **str, int minus, int point, int new_len);
int			ft_precision_e(char **new_nb, t_arg *arg);
int			ft_put_width(char **tab, t_arg *arg, int *i, int nbb);
int			ft_print_twob(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_treeb(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_fourb(char **ret, unsigned int wch, t_arg *arg);
int			ft_print_oneb(char **ret, unsigned int wch, t_arg *arg);
int			ft_regle_de_merde(char **ret, t_arg *arg);
void		ft_fill_str_ud(char **str, long long nb, int *len, t_arg *arg);
int			ft_init_conv_bigs(char **ret, t_arg *arg);
void		ft_precision_f(char *str, int p);
char		*flag_width_f(char *str, int width);
char		*right_justify_f(char *str, int width);
char		*left_justify_f(char *str, int width);
int			ft_flags_f(char **str, int sign, t_arg *arg);
char		*ft_arrondis_f(char *s, int p);
char		ft_getheight(t_arg *arg);
int			ft_length_cs(t_arg *argi);
int			ft_add_conv_s(char **ret, t_arg *arg);
int			ft_add_conv_bigc(char **ret, t_arg *arg);
int			ft_checknull_bigs(char **ret, t_arg *arg, char **str, wchar_t **x);
int			ft_add_conv_bigs(char **ret, t_arg *arg, wchar_t *x, int cmpt);
int			ft_strlenw_bigs(wchar_t wch);
char		**ft_strw_cpy(char **str, int start, char *tmp);
void		ft_check_nbcar(t_arg *arg, int *nbcar, wchar_t *x, int *strl);
int			ft_init_conv_bigs(char **ret, t_arg *arg);
int			ft_strlenw(wchar_t wch);

char		*ft_replace_stars(char *cpy, long long nb_len, int total, int *i);
int			ft_check_error_flag(t_arg *arg);

int			ft_forest(char **ret, t_arg *arg, va_list ap);
int			ft_checkconv(char **ret, t_arg *arg, va_list ap);
void		ft_initarg(t_arg *arg);
int			ft_check(char **ret, char *str, va_list ap, t_arg *arg);
int			ft_parse(char **retour, const char *format, va_list ap, t_arg *arg);

int			ft_cleanstars(char **str, va_list ap);

char		*ft_strfreejoin(char *s1, const char *s2, int size_s2, t_arg *arg);

int			ft_color(char **str, t_arg *arg);
void		ft_init_color(t_color *color);

#endif
