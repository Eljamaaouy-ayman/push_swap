/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:42:41 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/06 20:35:45 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_numbers **list_nbr)
{
	t_numbers	*first;
	t_numbers	*second;

	if (!list_nbr || !(*list_nbr) || !(*list_nbr)->next)
		return ;
	if (*list_nbr && (*list_nbr)->next)
	{
		first = *list_nbr;
		second = (*list_nbr)->next;
		first->next = second->next;
		second->next = first;
		*list_nbr = second;
	}
}

void	sb(t_numbers **list_nbr)
{
	t_numbers	*first;
	t_numbers	*second;

	if (!list_nbr || !(*list_nbr) || !(*list_nbr)->next)
		return ;
	if (*list_nbr && (*list_nbr)->next)
	{
		first = *list_nbr;
		second = (*list_nbr)->next;
		first->next = second->next;
		second->next = first;
		*list_nbr = second;
	}
}

void	ss(t_numbers **list_a, t_numbers **list_b)
{
	sa(list_a);
	sa(list_b);
}

void	pa(t_numbers **list_a, t_numbers **list_b)
{
	t_numbers	*first;

	if (!list_b || !(*list_b))
		return ;
	first = *list_b;
	*list_b = (*list_b)->next;
	first->next = *list_a;
	*list_a = first;
}

void	pb(t_numbers **list_a, t_numbers **list_b)
{
	t_numbers	*first;

	if (!list_b || !(*list_b))
		return ;
	first = *list_b;
	*list_b = (*list_b)->next;
	first->next = *list_a;
	*list_a = first;
}
