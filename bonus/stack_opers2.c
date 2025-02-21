/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:10:09 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/06 20:35:20 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_numbers **list_a)
{
	t_numbers	*ptr;
	t_numbers	*ptr2;

	if (!(*list_a) || !(*list_a)->next)
		return ;
	ptr = *list_a;
	while ((ptr)->next != NULL)
	{
		ptr2 = ptr;
		ptr = ptr->next;
	}
	ptr2->next = NULL;
	ptr->next = *list_a;
	*list_a = ptr;
}

void	rrb(t_numbers **list_a)
{
	t_numbers	*ptr;
	t_numbers	*ptr2;

	if (!(*list_a) || !(*list_a)->next)
		return ;
	ptr = *list_a;
	ptr2 = NULL;
	while ((ptr)->next != NULL)
	{
		ptr2 = ptr;
		ptr = ptr->next;
	}
	if (ptr2)
		ptr2->next = NULL;
	ptr->next = *list_a;
	*list_a = ptr;
}

void	rrr(t_numbers **list_a, t_numbers **list_b)
{
	rra(list_a);
	rrb(list_b);
}

void	free_split(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i] != NULL)
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	free_stack(t_numbers **stack_a)
{
	t_numbers	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}
