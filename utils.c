/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:32:48 by akostrik          #+#    #+#             */
/*   Updated: 2023/07/07 21:26:28 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *str_error, t_lst **l)
{
	ft_printf("%s, errno = %d\n", str_error, errno);
	if (l != NULL)
		free_(l);
	exit(EXIT_FAILURE);
}

void	print(t_lst **l)
{
	t_lst	*cur;

	cur = *l;
	while (cur != NULL && cur->nxt != NULL)
		cur = cur->nxt;
	while (cur != NULL)
	{
		ft_printf("%c", cur->c);
		cur = cur->prv;
	}
}

void	free_(t_lst **l)
{
	t_lst	*cur;
	t_lst	*to_free;

	cur = *l;
	while (cur != NULL && cur->nxt != NULL)
		cur = cur->nxt;
	while (cur != NULL)
	{
		to_free = cur;
		cur = cur->prv;
		free(to_free);
	}
	*l = NULL;
}

void	print_and_free(t_lst **l)
{
	print(l);
	free_(l);
}

void	put(t_lst **l, char c)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		error("malloc error", l);
	new->c = c;
	new->nxt = *l;
	new->prv = NULL;
	if (*l != NULL)
		(*l)->prv = new;
	*l = new;
}
