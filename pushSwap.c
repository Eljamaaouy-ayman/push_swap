/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:09:08 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 10:46:17 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_numbers **num_list, t_numbers **list_b)
{
	int (size), (i), (max);
	size = numsize(*list_b);
	if (!num_list || !list_b || !*list_b)
		return ;
	while (*list_b)
	{
		i = 0;
		max = get_index(*list_b, get_max(*list_b));
		if (max < size / 2)
		{
			while (i++ < max - 1)
				rb(list_b);
		}
		else
		{
			while (i < (size - max + 1))
			{
				rrb(list_b);
				i++;
			}
		}
		pa(num_list, list_b);
		size--;
	}
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

void	sort(t_numbers **num_list, t_numbers **list_b)
{
	int	*tab;

	if (numsize(*num_list) <= 5)
		sort_five(num_list, list_b);
	else
	{
		tab = sort_tab(*num_list, numsize(*num_list));
		push_to_b(num_list, list_b, tab, get_size(numsize(*num_list)));
		push_to_a(num_list, list_b);
		free(tab);
	}
}

int	main(int ac, char **av)
{
	t_numbers (*num_list);
	t_numbers (*list_b);
	num_list = NULL;
	list_b = NULL;
	if (ac < 2 || av[1][0] == '\0')
		return (0);
	parsing(ac, av, &num_list);
	if (check_sort(num_list) == 0)
		return (free_stack(&num_list), exit(1), 0);
	sort(&num_list, &list_b);
	free_stack(&num_list);
}
