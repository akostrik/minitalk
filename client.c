/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:16 by akostrik          #+#    #+#             */
/*   Updated: 2023/07/07 21:05:43 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Invalid number of params");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Incorrect PID");
			exit(EXIT_FAILURE);
		}
	}
	if (ft_atoi(argv[1]) == 0)
	{
		ft_printf("Incorrect PID");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		bit;
	int		send;
	char	*c;

	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	bit = 0;
	c = argv[2];
	usleep(3000);
	while (1)
	{
		send = ((*c) >> (7 - bit)) & 0b00000001;
		kill(pid, (send == 0) * SIG0 + (send == 1) * SIG1);
		if (*c == '\0' && bit == 7)
			break ;
		c += (bit == 7);
		bit = (bit + 1) % 8;
		usleep(600);
	}
	return (0);
}
