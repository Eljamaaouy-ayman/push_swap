/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:46:33 by ael-jama          #+#    #+#             */
/*   Updated: 2025/01/14 09:53:05 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int count_moves(numbers *list1, numbers *list2, numbers *ptr)
{
	int moves = 0;
	numbers *ptr2 = list2;
	numbers *ptr3;
	while (ptr2 != NULL && ptr2->next != NULL)
	{
		ptr3 = ptr2->next;
		if ((ptr->number > ptr3->number && ptr->number < ptr2->number) || 
			((ptr->number > get_max(list2) || ptr->number < get_min(list2)) && ptr2->number == get_max(list2)))
		{
			if (ptr->number > get_max(list2) || ptr->number < get_min(list2))
				ptr3 = ptr2;
			break;
		}
		ptr2 = ptr2->next;
	}
	if(same_move(list1, list2, ptr, ptr3) != 0)
		return (same_move(list1, list2, ptr, ptr3));
	if(get_index(list1, ptr->number) <= numsize(list1) / 2)
		moves = get_index(list1, ptr->number);
	else
		moves = numsize(list1) - get_index(list1, ptr->number) + 2;
	if(get_index(list2, ptr3->number) <= numsize(list2) / 2)
		moves += get_index(list2, ptr3->number) - 1;
	else
		moves += numsize(list2) - get_index(list2, ptr3->number) + 1;
	return moves;
}

numbers *find_cheapest(numbers *list, numbers *list2)
{
    int cheapest;
    numbers *ptr = list;
    numbers *ptr2 = list;

    cheapest = count_moves(list, list2, ptr);
    while (ptr != NULL)
    {
        if (count_moves(list, list2, ptr) < cheapest)
        {
            ptr2 = ptr; // Update the cheapest pointer
            cheapest = count_moves(list, list2, ptr); // Update the cheapest cost
        }
			// printf("the moves of %d are %d\n",ptr->number , count_moves(list, list2, ptr));
        ptr = ptr->next;
    }
    return ptr2;
}
int get_min(numbers *list)
{
	int min;
	numbers *ptr;

	if (list == NULL)
		return 0;
	ptr = list;
	min = ptr->number;
	while(ptr != NULL)
	{
		if (ptr->number < min)
			min = ptr->number;
		ptr = ptr->next;
	}
	return min;
}

int get_max(numbers *list)
{
	int max;
	numbers *ptr;

	if (list == NULL)
		return 0;
	ptr = list;
	max = ptr->number;
	while(ptr != NULL)
	{
		if (ptr->number > max)
			max = ptr->number;
		ptr = ptr->next;
	}
	return max;
}
int same_move(numbers *list1, numbers*list2, numbers *ptr, numbers*ptr2)
{
	if (!list1 || !list2 || !ptr || !ptr2) // Handle NULL pointers
		return 0;
	if(get_index(list1, ptr->number) <= numsize(list1) / 2 && get_index(list2, ptr2->number) <= numsize(list2) / 2)
	{
		if(get_index(list1, ptr->number) >= get_index(list2, ptr2->number))
			return get_index(list1, ptr->number);
		else
			return get_index(list2, ptr2->number);
	}
	else if(get_index(list1, ptr->number) > numsize(list1) / 2 && get_index(list2, ptr2->number) > numsize(list2) / 2)
	{
		if(numsize(list1) - get_index(list1, ptr->number) >= numsize(list2) - get_index(list2, ptr2->number))
			return numsize(list1) - get_index(list1, ptr->number) + 2;
		else
			return numsize(list2) - get_index(list2, ptr2->number) + 2;
	}
	return (0);
}