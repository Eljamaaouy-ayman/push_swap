/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:09:18 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/06 20:35:31 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_numbers **list_a)
{
	t_numbers	*first;
	t_numbers	*ptr;

	if (!(*list_a) || !(*list_a)->next)
		return ;
	first = *list_a;
	*list_a = first->next;
	first->next = NULL;
	ptr = *list_a;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = first;
}

void	rb(t_numbers **list_a)
{
	t_numbers	*first;
	t_numbers	*ptr;

	if (!(*list_a) || !(*list_a)->next)
		return ;
	first = *list_a;
	*list_a = first->next;
	first->next = NULL;
	ptr = *list_a;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = first;
}

void	rr(t_numbers **list_a, t_numbers **list_b)
{
	ra(list_a);
	rb(list_b);
}
