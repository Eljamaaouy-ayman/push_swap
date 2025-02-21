/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:10:09 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 10:48:01 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_numbers **list)
{
	t_numbers	*tmp;
	t_numbers	*move;

	if (!list || !(*list) || !((*list)->next))
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	move = *list;
	while (move->next)
		move = move->next;
	move->next = tmp;
}

void	rr(t_numbers **a, t_numbers **b)
{
	r(a);
	r(b);
	write(1, "rr\n", 3);
}

void	s(t_numbers **list)
{
	t_numbers	*first;
	t_numbers	*second;
	int			tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	second = (*list)->next;
	tmp = first->number;
	first->number = second->number;
	second->number = tmp;
}

void	ss(t_numbers **a, t_numbers **b)
{
	s(a);
	s(b);
	write(1, "ss\n", 3);
}

void	rrrr(t_numbers **list)
{
	t_numbers	*tmp;
	t_numbers	*move;

	if (!list || !(*list) || !(*list)->next)
		return ;
	move = *list;
	while (move->next)
	{
		tmp = move;
		move = move->next;
	}
	tmp->next = NULL;
	move->next = *list;
	*list = move;
}
