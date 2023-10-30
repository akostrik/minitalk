/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:16 by akostrik          #+#    #+#             */
/*   Updated: 2023/07/07 21:27:38 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sig;

static void	react_to_sig(int sig)
{
	g_sig = sig;
}

static void	loop(void)
{
	unsigned char	mask;
	char			c;
	t_lst			**l;

	mask = 0b10000000;
	c = 0b00000000;
	l = (t_lst **)malloc(sizeof(t_lst *));
	if (l == NULL)
		error("malloc error", l);
	*l = NULL;
	while (1)
	{
		pause();
		if (g_sig == SIG1)
			c = c | mask;
		if (mask == 0b000000001 && c == 0b00000000)
			print_and_free(l);
		else if (mask == 0b000000001 && c != 0b00000000)
		{
			put(l, c);
			c = 0b00000000;
		}
		mask = mask >> 1 | mask << 7;
	}
}

int	main(void)
{
	ft_printf("%d\n", (int)getpid());
	signal(SIG0, react_to_sig);
	signal(SIG1, react_to_sig);
	loop();
}
