/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:13:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/20 17:13:32 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <sys/types.h>
# include "colors.h"
# define BUFF_SIZE 1000

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			ft_bzero(void *s, size_t n);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*get_word(char *str, int n);
char			**ft_strsplit(char const *s, char c);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_sort_strtab(char **tab, char *type);
size_t			ft_strlcat(char *dest, char *src, size_t dstsize);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstpushback(t_list **alst, void *content, size_t size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				get_next_line(const int fd, char **line);
int				ft_printf(const char *format, ...);
char			*ft_strnchr(const char *s, int c, int size);
wchar_t			*ft_wstrdup(wchar_t *src);

typedef struct	s_params
{
	const char	*str;
	size_t		length;
	char		convert;
	int			width;
	size_t		index;
	size_t		ret_point;
	char		*data;
	char		mod;
	int			prec;
	int			hash;
	int			zero;
	int			space;
	int			minus;
	char		plus;
	int			apostrophe;
	int			error;
	int			p;
}				t_params;

t_params		*ft_get_struct(const char *fmt);
void			ft_check_pad(t_params *par, int *ret);
void			ft_get_param(t_params *par, va_list arg);
void			check_err_conv(t_params *par, const char c);
void			ft_write(const char *c, int *ret, int size);
void			ft_write_string(const char *s, int index, int *ret);
void			ft_write_free_string(t_params *par, int index, int *ret);
void			ft_write_wstring(unsigned char *s, int *ret, int len);
void			ft_printf_char(t_params *par, va_list arg, int *ret);
void			ft_printf_c_err(t_params *par, int *ret);
void			ft_printf_string(t_params *par, va_list arg, int *ret, int a);
void			ft_wchar_err(int *len, int num, t_params *par, int *index);
void			ft_printf_wchar(t_params *par, va_list arg, int *ret);
void			ft_printf_wstr(t_params *par, va_list arg, int *ret, int len);
unsigned char	*get_wlength(int *len, int index, t_params *par, va_list arg);
void			ft_printf_i(t_params *par, va_list arg, int *ret, int len);
void			ft_put_sign(t_params *par, int *ret, int *a);
uintmax_t		ft_get_num(t_params *par, uintmax_t n, intmax_t s, va_list arg);
uintmax_t		ft_get_uint(t_params *par, uintmax_t n, va_list arg);
int				ft_putnum(uintmax_t num, int *ret, t_params *par);
void			ft_place_int(t_params *par, int *ret, int *a, uintmax_t num);
void			ft_place_oct(t_params *par, int *ret, int *a, uintmax_t num);
void			ft_place_hex(t_params *par, int *ret, int *a, uintmax_t num);
void			ft_int_pad(t_params *par, int *ret, int *a);
int				ft_puthex(uintmax_t num, int *ret, t_params *par);
int				ft_putoct(uintmax_t num, int *ret, t_params *par);
void			ft_printf_hex(t_params *par, va_list arg, int *ret, int a);
void			ft_printf_oct(t_params *par, va_list arg, int *ret, int a);
void			ft_printf_double(t_params *par, va_list arg, int *ret, int a);
int				ft_words_count(char *str);
int				ft_count_in_array(char **arr, char *str);
int				ft_isdigit_str(char *str);
int				ft_intlen(int nbr);
void			ft_clean_str_array(char **arr);
int				ft_strcmp_nocase(const char *s1, const char *s2);

#endif
