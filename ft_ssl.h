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

# define FUNCTIONS 2
# define FUNC_NAME 7
# define FLAGS "pqrs"
# define MAX 9223372036854775807
# define BUF 10000

typedef struct		s_ssl_func
{
	char			func[FUNC_NAME];
	char			type[3];
	void			(*handler)(int, char**);
}					t_ssl_func;

typedef struct		s_file
{
	int				fd;
	char			*target;
	char			*string;
	int				p;
	int				q;
	int				r;
	int				s;
}					t_file;

typedef struct		s_flags
{
	int				nomore;
	int				p;
	int				q;
	int				r;
	int				s;
	int				stdin;
}					t_flags;

void				md5(int argc, char **argv);
void				sha256(int argc, char **argv);
void				wrong_argument(t_ssl_func handler[], char **argv, int i);
char				*ssl_read_stdin(size_t *len, int i, t_flags *flags);
char				*ssl_read_file(char *arg, size_t *length, char f[],
					char **file);
char				*ft_strjoin_size(char const *s1, char const *s2,
					size_t size);
void				usage(void);
#endif
