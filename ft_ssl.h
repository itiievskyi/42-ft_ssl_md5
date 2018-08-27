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
# include <stdbool.h>

# define FUNCTIONS 2
# define FUNC_NAME 7

typedef struct	s_ssl_func
{
	char		func[FUNC_NAME];
	char		type[3];
	void		(*handler)(int, char**);
}				t_ssl_func;

void			md5(int argc, char **argv);
void			sha256(int argc, char **argv);
void			wrong_argument(t_ssl_func handler[], char **argv, int i);
void			usage(void);
#endif
