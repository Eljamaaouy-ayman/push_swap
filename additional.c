/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:25:54 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 16:46:37 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(t_numbers *nums, int size)
{
	int (*tab), (swap), (i);
	tab = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		tab[i++] = nums->number;
		nums = nums->next;
	}
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void	incre_index(int *i, int *size, int list_size)
{
	if ((*i) < (*size))
		(*i)++;
	if ((*size) < list_size - 1)
		(*size)++;
}

void	push_to_b(t_numbers **stack_a, t_numbers **stack_b, int *tab, int size)
{
	int (size_lst), (start), (end);
	start = 0;
	end = size;
	size_lst = numsize(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->number <= tab[start])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			incre_index(&start, &end, size_lst);
		}
		else if ((*stack_a)->number <= tab[end])
		{
			pb(stack_a, stack_b);
			if ((*stack_b) && (*stack_b)->next
				&& (*stack_b)->number < (*stack_b)->next->number)
				sa(stack_a);
			incre_index(&start, &end, size_lst);
		}
		else
			ra(stack_a);
	}
}

int	get_size(int nbr)
{
	if (nbr <= 100)
		return (nbr / 6);
	else if (nbr <= 500)
		return (nbr / 14);
	else
		return (nbr / 20);
}

void	freeing(char **split_args, t_numbers **num_list)
{
	free_split(split_args);
	free_stack(num_list);
	write (2, "Error\n", 6);
	exit(1);
}
