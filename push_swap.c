/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:09:05 by ael-jama          #+#    #+#             */
/*   Updated: 2025/01/10 12:26:08 by ael-jama         ###   ########.fr       */
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
int same_move(numbers *list1, numbers*list2, numbers *ptr, numbers*ptr2)
{
	if(get_index(list1, ptr->number) <= numsize(list1) / 2 && get_index(list2, ptr2->number) <= numsize(list2) / 2)
	{
		if(get_index(list1, ptr->number) >= get_index(list2, ptr2->number))
			return get_index(list1, ptr->number);
		else
			return get_index(list2, ptr2->number);
	}
	else if(get_index(list1, ptr->number) > numsize(list1) /2 && get_index(list2, ptr2->number) > numsize(list2) / 2)
	{
		if(numsize(list1) - get_index(list1, ptr->number) >= numsize(list2) - get_index(list2, ptr2->number))
			return numsize(list1) - get_index(list1, ptr->number);
		else
			return numsize(list2) - get_index(list2, ptr2->number);
	}
	return (0);
}
int get_min(numbers *list)
{
	int min;
	numbers *ptr;

	ptr = list;
	min = 2147483647;
	while(ptr != NULL)
	{
		if (ptr->number < min)
			min = ptr->number;
	}
	return min;
}

int get_max(numbers *list)
{
	int max;
	numbers *ptr;

	ptr = list;
	max = -2147483648;
	while(ptr != NULL)
	{
		if (ptr->number > max)
			max = ptr->number;
	}
	return max;
}
int find_cheapest(numbers *list, numbers *list2)
{
	int cheapest;
	numbers *ptr;
	numbers *ptr2;

	cheapest = 	4294967295;
	while(ptr != NULL)
	{
		if (count_moves(list, list2, ptr,ptr2) < cheapest)
			cheapest = count_moves(list, list2, ptr,ptr2);
		ptr = ptr->next;
	}
	return cheapest;
}
int count_moves(numbers *list1, numbers *list2, numbers *ptr, numbers *ptr2)
{
	int moves;

	if(same_move(list1, list2, ptr, ptr2) != 0)
		return (same_move(list1, list2, ptr, ptr2) + 1);
	if(get_index(list1, ptr->number) <= numsize(list1) / 2)
		moves = get_index(list1, ptr->number);
	else
		moves = numsize(list1) - get_index(list1, ptr->number) + 2;
	while(ptr2->next != NULL)
	{
		if((ptr->number < ptr2->number && ptr->number > ptr2->next->number) || (ptr->number > get_max(list2) && ptr2->number == get_max(list2)) || (ptr->number < get_min(list2) && ptr2->number == get_max(list2)))
		{
			if(get_index(list2, ptr2->number) <= numsize(list2) / 2)
				moves += get_index(list2, ptr2->number) - 1;
			else
				moves += numsize(list2) - get_index(list2, ptr2->number);
		}
		ptr2 = ptr2->next;
	}
	ptr = ptr->next;
	return moves;
}

void swap_three(numbers **list1)
{
	numbers *list2;

	list2 = NULL;
	while(numsize(*list1) > 3)
		pa(&list2, list1);
	numbers *ptr = *list1;
	// printf("%d\n", ptr->number);
	// printf("%d, %d, %d", ptr->number, ptr->next->number, ptr->next->next->number);
	if(ptr->number < ptr->next->number && ptr->number > (ptr->next)->next->number)
		rra(list1);
	else if (ptr->number > ptr->next->number && ptr->next->number < ptr->next->next->number && ptr->number > ptr->next->next->number)
		ra(list1);
	else if(ptr->number > ptr->next->number)
	{
		sa(list1);
		if((*list1)->number > (*list1)->next->next->number && (*list1)->next->number > (*list1)->next->next->number)
			rra(list1);
	}
	else if(ptr->number < ptr->next->number && ptr->next->next->number > ptr->number && ptr->next->next->number < ptr->next->number)
	{
		sa(list1);
		ra(list1);
	}
	printf("%d, %d, %d", (*list1)->number, (*list1)->next->number, (*list1)->next->next->number);
}
//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
int main(int ac, char **av){
    int i;

    i = 1;
    numbers *num_list = NULL;
    while(i < ac)
    {
        ft_numadd_back(&num_list, new_num(ft_atoi(av[i])));
        i++;
    }
    swap_three(&num_list);
}
