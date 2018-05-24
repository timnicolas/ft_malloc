/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:15:42 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/16 15:32:49 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <struct.h>
# include <wchar.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# define BUFF_SIZE 32552

# define PRINTF_ERROR -1

# define GNL_END 0
# define GNL_LINE_READ 1
# define GNL_SUCCESS 1
# define GNL_ERROR -1

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
# define BOLD "\e[1m"
# define LIGHT "\e[2m"
# define ITALIC "\e[3m"
# define ULINE "\e[4m"

# define MASK01 0x0101010101010101
# define MASK80 0x8080808080808080

size_t		ft_strlen(const char *s);
void		ft_putchar(char c);
void		ft_putstr(const char *s);
void		ft_putendl(const char *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(const char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_isspace(int c);
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **ap);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int			ft_strequ(const char *s1, const char *s2);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s);
char		**ft_strsplit(const char *s, char c);
char		*ft_strdup(const char *s1);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstget(t_list *lst, int n);

int			ft_max(int a, int b);
int			ft_min(int a, int b);
size_t		ft_intlen(int n);
long long	ft_atol(const char *nptr);
void		*ft_realloc(void *ptr, size_t original_size, size_t new_size);
int			ft_read_fd(int fd, char **file_content);
int			ft_read_file(char *filename, char **file_content);
char		*ft_int_to_base(long long n, char *base);
char		*ft_int_to_nbase(long n, char *base, int size);
long long	ft_base_to_int(char *n, char *base);
int			ft_atoi_base(char *s, char *base);
char		*ft_convert_base(char *n, char *base_in, char *base_out);
char		*ft_ftoa(double f, int sign);
char		*ft_ltoa(long n);
char		*ft_lltoa(long long n);
unsigned	ft_abs(int nb);
int			ft_free(size_t n, ...);
int			ft_fruit(size_t n, ...);
int			ft_free_tab(size_t n, ...);
int			ft_fruit_tab(size_t n, ...);
char		*ft_strndup(const char *s1, int n);
double		ft_power(double nb, int power);
long long	ft_2arg(int arg1, int arg2);
int			ft_get2arg(long long arg, int n);
void		ft_swap_int(int *a, int *b);
char		*ft_clean_char(char *s, char c);
void		ft_test_malloc(size_t size);
int			get_next_line(const int fd, char **line);

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);
int			ft_errprintf(const char *format, ...);
int			ft_verrprintf(const char *format, va_list ap);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list ap);
int			ft_asprintf(char **str, const char *format, ...);
int			ft_vasprintf(char **ret, const char *format, va_list ap);
int			ft_joinprintf(char **str, const char *format, ...);
int			ft_joinnprintf(char **str, int n, const char *format, ...);

#endif
