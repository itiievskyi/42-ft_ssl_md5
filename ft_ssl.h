/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:15:29 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/24 11:15:32 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>

# define FUNCTIONS 7
# define FUNC_NAME 10
# define FLAGS "pqrs"
# define MAX 9223372036854775807
# define BUF 10000
# define HEX "0123456789abcdef"

typedef struct	s_ssl_func
{
	char		func[FUNC_NAME];
	char		type[3];
	void		(*handler)(int, char**);
}				t_ssl_func;

typedef struct	s_file
{
	int			fd;
	char		*target;
	char		*string;
	int			p;
	int			q;
	int			r;
	int			s;
}				t_file;

typedef struct	s_flags
{
	int			nomore;
	int			p;
	int			q;
	int			r;
	int			s;
	int			stdin;
}				t_flags;

void			init_functions(t_ssl_func handler[FUNCTIONS]);
void			stdin_cmd(int argc, int i, t_ssl_func handler[], bool no_error);
void			md5(int argc, char **argv);
void			sha256(int argc, char **argv);
void			sha224(int argc, char **argv);
void			sha512(int argc, char **argv);
void			sha512224(int argc, char **argv);
void			sha512256(int argc, char **argv);
void			sha384(int argc, char **argv);
int				flags_init(t_flags *flags);
void			wrong_argument(t_ssl_func handler[], char **argv, int i);
char			*ssl_read_stdin(size_t *len, int i, t_flags *flags);
char			*ssl_read_file(char *arg, size_t *length, char f[],
				char **file);
char			*ft_strjoin_size(char const *s1, char const *s2, size_t size);
void			usage(void);
void			check_extra_flags(t_flags *flags, char flag, char f[]);
void			ssl_s_error(t_flags *flags, char f[]);
void			ssl_err_flag(char ch, t_flags *flags, char f[]);
char			*ft_itoa_hex(uint32_t state[], int size, int i, char end);
char			*ft_itoa_hex_512(uint64_t state[], int size, int i, char end);
void			clean_array(char **arr);
#endif
