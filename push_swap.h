/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:14:09 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/07 16:46:55 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct n_struct
{
	int				number;
	struct n_struct	*next;
}					t_numbers;

void				pa(t_numbers **a, t_numbers **b);
void				pb(t_numbers **b, t_numbers **a);
void				ra(t_numbers **list);
void				rb(t_numbers **list);
void				sa(t_numbers **list);
void				sb(t_numbers **list);
void				ss(t_numbers **a, t_numbers **b);
void				rr(t_numbers **a_list, t_numbers **b_list);
void				rra(t_numbers **list);
void				rrb(t_numbers **list);
void				rrr(t_numbers **a, t_numbers **b);
void				rrrr(t_numbers **list);
void				sort_five(t_numbers **a, t_numbers **b);
int					is_only_spaces(char *str);
int					get_min(t_numbers *list);
int					get_max(t_numbers *list);
int					numsize(t_numbers *lst);
long				ft_atoi(const char *str);
t_numbers			*ft_numlast(t_numbers *lst);
void				ft_numadd_back(t_numbers **lst, t_numbers *new);
t_numbers			*new_num(int num);
int					get_index(t_numbers *list, int number);
void				freeing(char **split_args, t_numbers **num_list);
int					duplicate(t_numbers *num_list);
char				**ft_split(char const *s, char c);

int					check_list(char *split_args, t_numbers **num_list);
int					check_str(char *str);
int					check_sort(t_numbers *num_list);
void				parsing(int ac, char **av, t_numbers **num_list);

void				sort(t_numbers **num_list, t_numbers **list_b);
void				free_stack(t_numbers **stack_a);
void				free_split(char **split_args);
void				push_to_a(t_numbers **num_list, t_numbers **list_b);
int					get_size(int nbr);
void				push_to_b(t_numbers **stack_a, t_numbers **stack_b,
						int *tab, int size);
void				incre_index(int *i, int *size, int list_size);
int					*sort_tab(t_numbers *nums, int size);

#endif