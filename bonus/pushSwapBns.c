/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwapBns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:36:16 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 11:33:56 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	make_opera(char *oper, t_numbers **num_list, t_numbers **list_b)
{
	if (ft_strcmp(oper, "sa\n") == 0)
		sa(num_list);
	else if (ft_strcmp(oper, "sb\n") == 0)
		sb(list_b);
	else if (ft_strcmp(oper, "ss\n") == 0)
		ss(list_b, num_list);
	else if (ft_strcmp(oper, "pa\n") == 0)
		pa(num_list, list_b);
	else if (ft_strcmp(oper, "pb\n") == 0)
		pb(list_b, num_list);
	else if (ft_strcmp(oper, "ra\n") == 0)
		ra(num_list);
	else if (ft_strcmp(oper, "rb\n") == 0)
		rb(list_b);
	else if (ft_strcmp(oper, "rr\n") == 0)
		rr(list_b, num_list);
	else if (ft_strcmp(oper, "rra\n") == 0)
		rra(num_list);
	else if (ft_strcmp(oper, "rrb\n") == 0)
		rrb(list_b);
	else if (ft_strcmp(oper, "rrr\n") == 0)
		rrr(list_b, num_list);
	else
		return (0);
	return (1);
}

void	check_opera(t_numbers **num_list, t_numbers **list_b)
{
	char	*oper;

	oper = get_next_line(0);
	while (oper != NULL)
	{
		if (make_opera(oper, num_list, list_b) == 0)
		{
			free(oper);
			free_stack(num_list);
			free_stack(list_b);
			get_next_line(-10);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(oper);
		oper = get_next_line(0);
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
	check_opera(&num_list, &list_b);
	if (check_sort(num_list) == 0 && numsize(list_b) == 0)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
	}
	free_stack(&num_list);
	free_stack(&list_b);
}
