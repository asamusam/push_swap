/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:55:24 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/24 23:31:37 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_action_count_ab(t_list *a, t_list *b)
{
	int		i;
	int		current;
	t_list	*t;

	t = a;
	i = count_ra_rb(a, b, *(int *)a->content);
	while (t)
	{
		current = *(int *)t->content;
		if (count_ra_rb(a, b, current) < i)
			i = count_ra_rb(a, b, current);
		if (count_rra_rrb(a, b, current) < i)
			i = count_rra_rrb(a, b, current);
		if (count_ra_rrb(a, b, current) < i)
			i = count_ra_rrb(a, b, current);
		if (count_rra_rb(a, b, current) < i)
			i = count_rra_rb(a, b, current);
		t = t->next;
	}
	return (i);
}

void	sort_b(t_list **a, t_list **b)
{
	int			i;
	int			n;
	t_list		*t;

	while (ft_lstsize(*a) > 3 && !is_sorted(*a))
	{
		t = *a;
		i = min_action_count_ab(*a, *b);
		while (i >= 0)
		{
			n = *(int *)t->content;
			if (i == count_ra_rb(*a, *b, n))
				i = do_ra_rb(a, b, n, 'a');
			else if (i == count_rra_rrb(*a, *b, n))
				i = do_rra_rrb(a, b, n, 'a');
			else if (i == count_ra_rrb(*a, *b, n))
				i = do_ra_rrb(a, b, n, 'a');
			else if (i == count_rra_rb(*a, *b, n))
				i = do_rra_rb(a, b, n, 'a');
			else
				t = t->next;
		}
	}
}

void	fill_b(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 3 && !is_sorted(*a))
		push(a, b, 'b');
	if (ft_lstsize(*a) > 3 && !is_sorted(*a))
		push(a, b, 'b');
	if (ft_lstsize(*a) > 3 && !is_sorted(*a))
		sort_b(a, b);
	if (!is_sorted(*a))
		sort_three(a);
}
