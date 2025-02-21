/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:09:18 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 10:48:09 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_numbers **list)
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
	write(1, "sa\n", 3);
}

void	sb(t_numbers **list)
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
	write(1, "sb\n", 3);
}

void	pa(t_numbers **dst, t_numbers **src)
{
	t_numbers	*push_node;

	if (!src || !(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
	write(1, "pa\n", 3);
}

void	pb(t_numbers **src, t_numbers **dst)
{
	t_numbers	*push_node;

	if (!src || !(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
	write(1, "pb\n", 3);
}
