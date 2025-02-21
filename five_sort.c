/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:53:36 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 11:55:50 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_sec_min_(t_numbers *stack, int min)
{
	int	sec_min;

	sec_min = 2147483647;
	while (stack)
	{
		if (stack->number > min && stack->number < sec_min)
			sec_min = stack->number;
		stack = stack->next;
	}
	return (sec_min);
}

void	swap_three(t_numbers **list1)
{
	t_numbers (*list2);
	t_numbers (*ptr);
	list2 = NULL;
	ptr = *list1;
	if (ptr->number < ptr->next->number
		&& ptr->number > (ptr->next)->next->number)
		rra(list1);
	else if (ptr->number > ptr->next->number
		&& ptr->next->number < ptr->next->next->number
		&& ptr->number > ptr->next->next->number)
		ra(list1);
	else if (ptr->number > ptr->next->number)
	{
		sa(list1);
		if ((*list1)->number > (*list1)->next->next->number
			&& (*list1)->next->number > (*list1)->next->next->number)
			rra(list1);
	}
	else if (ptr->number < ptr->next->number
		&& ptr->next->next->number > ptr->number)
	{
		sa(list1);
		ra(list1);
	}
}

void	sort_five(t_numbers **a, t_numbers **b)
{
	if (numsize(*a) == 2)
	{
		if ((*a)->number > (*a)->next->number)
			sa(a);
		return ;
	}
	while (numsize(*a) > 3)
	{
		if ((*a)->number == get_min(*a) || (*a)->number == find_sec_min_(*a,
				get_min(*a)))
			pb(a, b);
		else
			ra(a);
	}
	swap_three(a);
	pa(a, b);
	if ((*a)->number > (*a)->next->number)
		sa(a);
	pa(a, b);
	if ((*a)->number > (*a)->next->number)
		sa(a);
	pa(a, b);
}
