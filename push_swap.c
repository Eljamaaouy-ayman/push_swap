/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:09:05 by ael-jama          #+#    #+#             */
/*   Updated: 2024/12/23 18:42:01 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	if(index(ptr) <= numsize(list1) / 2 && index(ptr2) <= numsize(list2) / 2)
	{
		if(index(ptr) >= index(ptr2))
			return index(ptr);
		else
			return index(ptr2);
	}
	else if(index(ptr) > numsize(list1) /2 && index(ptr2) > numsize(list2) / 2)
	{
		if(numsize(list1) - index(ptr) >= numsize(list2) - index(ptr2))
			return numsize(list1) - index(ptr);
		else
			return numsize(list2) - index(ptr2);
	}
	return (0);
}

int find_cheapest(numbers *list1, numbers*list2)
{
	int cheapest;
	numbers *ptr;
	numbers *ptr2;

	ptr = list1;
	ptr2 = list2;
	while(ptr->next != NULL)
	{
		if(get_index(list1, ptr->number) <= numsize(list1) / 2)
			cheapest = get_index(list1, ptr->number) - 1;
		else
			cheapest = numsize(list1) - get_index(list1, ptr->number) - 1;
		while(ptr2->next != NULL)
		{
			if(ptr->number < ptr2->number && ptr->number > ptr2->next->number)
			{
				if(get_index(list2, ptr2->number) <= numsize(list2) / 2)
					cheapest += get_index(list2, ptr2->number) - 1;
				else
					cheapest += numsize(list2) - get_index(list2, ptr2->number) - 1;
			}
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	//almost done but we don't return the cheapest one we should look for the cheapest one!!!!!
	return cheapest;
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
	else if(ptr->number < ptr->next->number && ptr->next->next->number > ptr->number)
	{
		sa(list1);
		ra(list1);
	}
	printf("%d, %d, %d", (*list1)->number, (*list1)->next->number, (*list1)->next->next->number);
}
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
