/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:30:08 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/06 22:45:29 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct n_struct
{
	int				number;
	struct n_struct	*next;
}					t_numbers;

void				sa(t_numbers **list_nbr);
void				sb(t_numbers **list_nbr);
void				ss(t_numbers **list_a, t_numbers **list_b);
void				pa(t_numbers **list_a, t_numbers **list_b);
void				pb(t_numbers **list_a, t_numbers **list_b);
void				ra(t_numbers **list_a);
void				rb(t_numbers **list_a);
void				rr(t_numbers **list_a, t_numbers **list_b);
void				rra(t_numbers **list_a);
void				rrb(t_numbers **list_a);
void				rrr(t_numbers **list_a, t_numbers **list_b);
int					is_only_spaces(char *str);
int					get_min(t_numbers *list);
int					get_max(t_numbers *list);
int					numsize(t_numbers *lst);
long				ft_atoi(const char *str);
t_numbers			*ft_numlast(t_numbers *lst);
void				ft_numadd_back(t_numbers **lst, t_numbers *new);
t_numbers			*new_num(int num);
int					get_index(t_numbers *list, int number);

int					duplicate(t_numbers *num_list);
char				**ft_split(char const *s, char c);

int					check_list(char *split_args, t_numbers **num_list);
int					check_str(char *str);
int					check_sort(t_numbers *num_list);
void				parsing(int ac, char **av, t_numbers **num_list);

void				free_stack(t_numbers **stack_a);
void				free_split(char **split_args);
int					get_size(int nbr);
int					ft_strcmp(char *s1, char *s2);

#endif