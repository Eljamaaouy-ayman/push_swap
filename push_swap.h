#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>


typedef struct n_struct{
    int             number;
    struct n_struct *next;
}               numbers;

int	ft_atoi(const char *str);
void sa(numbers **list_nbr);
void ss(numbers **list_a, numbers **list_b);
void pa(numbers **list_a, numbers **list_b);
void ra(numbers **list_a);
void rr(numbers **list_a, numbers **list_b);
void rra(numbers **list_a);
void rrr(numbers **list_a, numbers **list_b);
int count_moves(numbers *list1, numbers *list2, numbers *ptr);
int get_min(numbers *list);
int get_max(numbers *list);
int moves_and_push(numbers **list1, numbers **list2, numbers *ptr);
numbers *find_cheapest(numbers *list, numbers *list2);
int	numsize(numbers *lst);
numbers	*ft_numlast(numbers *lst);
void	ft_numadd_back(numbers **lst, numbers *new);
numbers	*new_num(int num);
int get_index(numbers *list, int number);
int push_same_move(numbers **list1, numbers **list2, numbers *ptr, numbers *ptr2);
void single_moves(numbers **list, int number, char s);
int same_move(numbers *list1, numbers*list2, numbers *ptr, numbers*ptr2);

#endif