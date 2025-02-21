/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:49:06 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/06 20:36:20 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atoi(const char *str)
{
	size_t	i;
	long	number;
	int		sign;

	sign = 1;
	i = 0;
	number = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		if (number > INT_MAX || number < INT_MIN)
			return (2147483650);
		i++;
	}
	return ((int)(number * sign));
}

t_numbers	*ft_numlast(t_numbers *lst)
{
	t_numbers	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	ft_numadd_back(t_numbers **lst, t_numbers *new)
{
	t_numbers	*ptr;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else if (new != NULL)
	{
		ptr = ft_numlast(*lst);
		ptr->next = new;
	}
}

t_numbers	*new_num(int num)
{
	t_numbers	*new_num;

	new_num = (t_numbers *)malloc(sizeof(t_numbers));
	if (new_num == NULL)
		return (NULL);
	new_num->number = num;
	new_num->next = NULL;
	return (new_num);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
