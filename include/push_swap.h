/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:26:47 by asamuilk          #+#    #+#             */
/*   Updated: 2024/02/25 22:15:39 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define STDERR 2
# include "libft.h"
# include <stdbool.h>
# include <limits.h>

bool	parse_input(char **av, t_list **a);
int		ft_atoi_mod(const char *nptr);
t_list	*ft_lstlast_mod(t_list *lst, int *num);
bool	ft_lstadd_back_mod(t_list **lst, t_list *new);

void	swap(t_list **x, char s);
void	push(t_list **x, t_list **y, char s);
void	rotate(t_list **x, char s);
void	rrotate(t_list **x, char s);
void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

bool	is_sorted(t_list *a);
void	sort_three(t_list **a);

void	fill_b(t_list **a, t_list **b);
void	fill_a(t_list **a, t_list **b);
void	final_sort_a(t_list **a);

int		ft_max(t_list *s);
int		ft_min(t_list *s);
int		get_index(t_list *s, int n);
int		get_target_index_a(t_list *a, int n);
int		get_target_index_b(t_list *b, int n);

int		count_ra_rb(t_list *a, t_list *b, int n);
int		count_rra_rrb(t_list *a, t_list *b, int n);
int		count_ra_rrb(t_list *a, t_list *b, int n);
int		count_rra_rb(t_list *a, t_list *b, int n);

int		count_ra_rb_a(t_list *a, t_list *b, int n);
int		count_rra_rrb_a(t_list *a, t_list *b, int n);
int		count_ra_rrb_a(t_list *a, t_list *b, int n);
int		count_rra_rb_a(t_list *a, t_list *b, int n);

int		do_ra_rb(t_list **a, t_list **b, int n, char s);
int		do_rra_rrb(t_list **a, t_list **b, int n, char s);
int		do_ra_rrb(t_list **a, t_list **b, int n, char s);
int		do_rra_rb(t_list **a, t_list **b, int n, char s);

#endif