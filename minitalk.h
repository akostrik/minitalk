/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:24:00 by akostrik          #+#    #+#             */
/*   Updated: 2023/07/07 21:26:34 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <aio.h>
# include <stdarg.h>
# include <limits.h>
# include <zconf.h>
# include <stdint.h>
# include "libft/libft.h"

# define SIG0 SIGUSR2
# define SIG1 SIGUSR1

typedef struct s_lst
{
	char			c;
	struct s_lst	*nxt;
	struct s_lst	*prv;
}	t_lst;

void	error(char *str_error, t_lst **l);
void	print(t_lst **l);
void	free_(t_lst **l);
void	print_and_free(t_lst **l);
void	put(t_lst **l, char c);

#endif
