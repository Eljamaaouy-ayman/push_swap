/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:09:05 by ael-jama          #+#    #+#             */
/*   Updated: 2025/01/15 20:54:45 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_back(numbers **list1, numbers **list2, numbers *ptr)
{
	numbers *ptr2;
	numbers *ptr3;

	ptr2 = *list2;
	ptr3 = ptr2;
	while(!((ptr->number > ptr3->number && ptr->number < ptr2->number) || (ptr->number > get_max(*list2) && ptr2->number == get_max(*list2)) || (ptr->number < get_min(*list2) && ptr2->number == get_min(*list2))) && ptr2 != NULL)
	{
		ptr3 = ptr2;
		ptr2 = ptr2->next;
	}
	printf("%d", ptr2->number);
	if(push_same_move(list1, list2, ptr, ptr2) != 0)
		return (pa(list2, list1), 0);
	if(get_index(*list1, ptr->number) <= numsize(*list1) / 2)
		single_moves(list1, get_index(*list1, ptr->number) - 1, 'u');
	else
		single_moves(list1, numsize(*list1) - get_index(*list1, ptr->number) + 1, 'd');
	if(get_index(*list2, ptr2->number) <= numsize(*list2) / 2)
		single_moves(list2, get_index(*list2, ptr2->number) - 1, 'u');
	else
		single_moves(list2, numsize(*list2) - get_index(*list2, ptr2->number) + 1, 'd');
	return (pa(list2, list1), 0);
}

int moves_and_push(numbers **list1, numbers **list2, numbers *ptr)
{
	numbers *ptr2;
	numbers *ptr3;

	ptr2 = *list2;
	ptr3 = ptr2;
	while(!((ptr->number < ptr3->number && ptr->number > ptr2->number) || (ptr->number > get_max(*list2) && ptr2->number == get_max(*list2)) || (ptr->number < get_min(*list2) && ptr2->number == get_max(*list2))) && ptr2 != NULL)
	{
		ptr3 = ptr2;
		ptr2 = ptr2->next;
	}
	if(push_same_move(list1, list2, ptr, ptr2) != 0)
		return (pa(list2, list1), 0);
	if(get_index(*list1, ptr->number) <= numsize(*list1) / 2)
		single_moves(list1, get_index(*list1, ptr->number) - 1, 'u');
	else
		single_moves(list1, numsize(*list1) - get_index(*list1, ptr->number) + 1, 'd');
	if(get_index(*list2, ptr2->number) <= numsize(*list2) / 2)
		single_moves(list2, get_index(*list2, ptr2->number) - 1, 'u');
	else
		single_moves(list2, numsize(*list2) - get_index(*list2, ptr2->number) + 1, 'd');
	return (pa(list2, list1), 0);
}
void single_moves(numbers **list, int number, char s)
{
	if(s == 'u')
	{
		while(number > 0)
		{
			ra(list);
			number--;
		}
	}

	if(s == 'd')
	{
		while(number > 0)
		{
			rra(list);
			number--;
		}
	}
}

void do_moves(numbers **list1, numbers **list2, int min, int other, char s)
{
	if(s == 'u'){
		while(min > 0)
		{
			rr(list1, list2);
			min--;
		}
		while(other > 0)
		{
			ra(list1);
			other--;
		}
	}
	else if(s == 'd')
	{
		while(min > 0)
		{
			rrr(list1, list2);
			min--;
		}
		while(other > 0)
		{
			rra(list1);
			other--;
		}
	}
}
int push_same_move(numbers **list1, numbers **list2, numbers *ptr, numbers *ptr2)
{
	int first_moves;
	int second_moves;

	if(get_index(*list1, ptr->number) <= numsize(*list1) / 2 && get_index(*list2, ptr2->number) <= numsize(*list2) / 2)
	{
		first_moves = get_index(*list2, ptr2->number) - 1;
		second_moves = get_index(*list1, ptr->number) - 1;
		if(first_moves < second_moves)
			do_moves(list1, list2, first_moves, second_moves - first_moves, 'u');
		else
			do_moves(list2, list1, second_moves, first_moves - second_moves, 'u');
		return 1;
	}
	else if(get_index(*list1, ptr->number) > numsize(*list1) / 2 && get_index(*list2, ptr2->number) > numsize(*list2) / 2)
	{
		first_moves = numsize(*list2) - get_index(*list2, ptr2->number) + 1;
		second_moves = numsize(*list1) - get_index(*list1, ptr->number) + 1;
		if(first_moves < second_moves)
			do_moves(list2, list1, second_moves, first_moves - second_moves, 'd');
		else
			do_moves(list1, list2, first_moves, second_moves - first_moves, 'd');
		return 1;
	}
	return 0;
}

void swap_three(numbers **list1)
{
	numbers *list2;
	numbers *ptr;

	list2 = NULL;
	ptr = *list1;
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
}
//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
int main(int ac, char **av){
	int i;

	i = 1;
	numbers *num_list = NULL;
	numbers *list_b = NULL;
	numbers *ptr;
	numbers *ptr2;
	while(i < ac)
	{
		ft_numadd_back(&num_list, new_num(ft_atoi(av[i])));
		i++;
	}
	while (numsize(num_list) > 4)
	{
		pa(&list_b, &num_list);
	}
	// while(numsize(num_list) > 3)
	// {
	// 	ptr = num_list;
	// 	moves_and_push(&num_list, &list_b, ptr);
	// }
	printf("==>%d\n",numsize(num_list));
	// swap_three(&num_list);


	printf("==>%d\n",numsize(num_list));
	ptr2 = list_b;
	// while(numsize(list_b) != 0)
	// {
		ptr = list_b;
		push_back(&list_b, &num_list, ptr);
		ptr = list_b;
		// printf("%d", ptr->number);
		// push_back(&list_b, &num_list, ptr);
	// }
		ptr = num_list;
		ptr2 = list_b;

		while(ptr != NULL){
			printf("%d\n", ptr->number);
			ptr = ptr->next;
		}
		printf("--------------------------\n");
		while(ptr2 != NULL){
			printf("%d\n", ptr2->number);
			ptr2 = ptr2->next;
		}
	// ./a.out 8 19 45 66 90 120 80 92 65 33 84
}
