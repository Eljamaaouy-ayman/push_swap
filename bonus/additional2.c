/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:02:14 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 10:06:42 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	numsize(t_numbers *lst)
{
	size_t		i;
	t_numbers	*ptr;

	if (lst == NULL)
		return (0);
	i = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int	get_index(t_numbers *list, int number)
{
	t_numbers	*ptr;
	int			i;

	i = 1;
	ptr = list;
	while (ptr->number != number)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	get_min(t_numbers *list)
{
	int			min;
	t_numbers	*ptr;

	if (list == NULL)
		return (0);
	ptr = list;
	min = ptr->number;
	while (ptr != NULL)
	{
		if (ptr->number < min)
			min = ptr->number;
		ptr = ptr->next;
	}
	return (min);
}

int	get_max(t_numbers *list)
{
	int			max;
	t_numbers	*ptr;

	if (list == NULL)
		return (0);
	ptr = list;
	max = ptr->number;
	while (ptr != NULL)
	{
		if (ptr->number > max)
			max = ptr->number;
		ptr = ptr->next;
	}
	return (max);
}

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
