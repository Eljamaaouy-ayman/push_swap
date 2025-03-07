/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:37:18 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 10:48:17 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_numbers **list)
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
	write(1, "ra\n", 3);
}

void	rb(t_numbers **list)
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
	write(1, "rb\n", 3);
}

void	rra(t_numbers **list)
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
	write(1, "rra\n", 4);
}

void	rrb(t_numbers **list)
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
	write(1, "rrb\n", 4);
}

void	rrr(t_numbers **a, t_numbers **b)
{
	rrrr(a);
	rrrr(b);
	write(1, "rrr\n", 3);
}
