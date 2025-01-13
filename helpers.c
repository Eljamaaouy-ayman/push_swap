/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:49:06 by ael-jama          #+#    #+#             */
/*   Updated: 2025/01/12 11:49:46 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
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
		if (number < 0)
			return ((-sign) * (sign == 1));
		i++;
	}
	return ((int)(number * sign));
}

numbers	*ft_numlast(numbers *lst)
{
	numbers	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	ft_numadd_back(numbers **lst, numbers *new)
{
	numbers	*ptr;

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

numbers	*new_num(int num)
{
	numbers	*new_num;

	new_num = (numbers *)malloc(sizeof(numbers));
	if (new_num == NULL)
		return (NULL);
	new_num->number = num;
	new_num->next = NULL;
	return (new_num);
}
int	numsize(numbers *lst)
{
	size_t	i;
	numbers	*ptr;

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
int get_index(numbers *list, int number)
{
	numbers	*ptr;
	int		i;

	i = 1;
	ptr = list;
	while(ptr->number != number)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
