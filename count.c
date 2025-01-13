/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:46:33 by ael-jama          #+#    #+#             */
/*   Updated: 2025/01/13 10:31:42 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int count_moves(numbers *list1, numbers *list2, numbers *ptr)
{
    int moves = 0;
    numbers *ptr2 = list2;
    numbers *ptr3 = NULL;

    // Traverse list2 to find the correct insertion point
    while (ptr2 != NULL)
    {
        ptr3 = ptr2->next;  // Set ptr3 to the next node of ptr2
        if ((ptr3 != NULL && ptr->number < ptr3->number && ptr->number > ptr2->number) || 
            (ptr->number > get_max(list2) && ptr2->number == get_max(list2)) || 
            (ptr->number < get_min(list2) && ptr2->number == get_max(list2)))
        {
            break;
        }
        ptr2 = ptr2->next;
    }
	if (ptr2 == NULL)
	return -1; 
	if(same_move(list1, list2, ptr, ptr2) != 0)
		return (same_move(list1, list2, ptr, ptr2));
		// printf("h");
	if(get_index(list1, ptr->number) <= numsize(list1) / 2)
		moves = get_index(list1, ptr->number);
	else
		moves = numsize(list1) - get_index(list1, ptr->number) + 2;
	// printf("moves %d\n", moves);
	if(get_index(list2, ptr2->number) <= numsize(list2) / 2)
		moves += get_index(list2, ptr2->number);
	else
		moves += numsize(list2) - get_index(list2, ptr2->number) + 2;
	return moves;
}

numbers *find_cheapest(numbers *list, numbers *list2)
{
	int cheapest;
	numbers *ptr;
	numbers *ptr2;

	ptr = list;
	cheapest = 	count_moves(list, list2, ptr);
	printf("the cheapest --> %d", cheapest);
	ptr2 = ptr;
	printf("the pointer --> %d", ptr2->number);
	// while(ptr != NULL)
	// {
	// 	// printf("the ptr %d, the moves %d\n", ptr->number, count_moves(list, list2, ptr));
	// 	if (count_moves(list, list2, ptr) < cheapest)
	// 	{
	// 		ptr2 = ptr;
	// 		cheapest = count_moves(list, list2, ptr);
	// 	}
	// 	ptr = ptr->next;
	// }
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
			// printf("%d", numsize(list1) - get_index(list1, ptr->number) + 2);
}