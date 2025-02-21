/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:58:52 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 16:48:49 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	parsing(int ac, char **av, t_numbers **num_list)
{
	char	**split_args;

	int (i), (j);
	if (is_only_spaces(av[1]))
		return (free_stack(num_list), write(2, "Error\n", 6), exit(1));
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '\0')
			return (free_stack(num_list), write(2, "Error\n", 6), exit(1));
		split_args = ft_split(av[i], ' ');
		if (split_args == NULL || split_args[0][0] == '\0')
			return (free_split(split_args), free_stack(num_list), write(2,
					"Error\n", 6), exit(1));
		j = 0;
		while (split_args[j])
		{
			if (check_list(split_args[j++], num_list) == -1)
				return (free_split(split_args), free_stack(num_list), write(2,
						"Error\n", 6), exit(1));
		}
		free_split(split_args);
	}
	if (duplicate(*num_list) == 0)
		return (free_stack(num_list), write(2, "Error\n", 6), exit(1));
}

int	check_sort(t_numbers *num_list)
{
	while (num_list->next)
	{
		if (num_list->number > num_list->next->number)
			return (-1);
		num_list = num_list->next;
	}
	return (0);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_list(char *split_args, t_numbers **num_list)
{
	long	value;

	if (check_str(split_args) == 0)
		return (-1);
	value = ft_atoi(split_args);
	if (value == 2147483650)
		return (-1);
	ft_numadd_back(num_list, new_num(value));
	return (0);
}

int	duplicate(t_numbers *lst)
{
	t_numbers	*move;
	t_numbers	*move_next;

	if (!lst)
		return (0);
	move = lst;
	while (move)
	{
		move_next = move->next;
		while (move_next)
		{
			if (move->number == move_next->number)
				return (0);
			move_next = move_next->next;
		}
		move = move->next;
	}
	return (1);
}
