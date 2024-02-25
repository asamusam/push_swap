/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:41:39 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/24 23:06:41 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort_a(t_list **a)
{
	int	i;
	int	min;

	min = ft_min(*a);
	i = get_index(*a, min);
	if (i < ft_lstsize(*a) - i)
	{
		while (*(int *)(*a)->content != min)
			rotate(a, 'a');
	}
	else
	{
		while (*(int *)(*a)->content != min)
			rrotate(a, 'a');
	}
}

int	min_action_count_ba(t_list *a, t_list *b)
{
	int		i;
	int		current;
	t_list	*t;

	t = b;
	i = count_ra_rb_a(a, b, *(int *)b->content);
	while (t)
	{
		current = *(int *)t->content;
		if (count_ra_rb_a(a, b, current) < i)
			i = count_ra_rb_a(a, b, current);
		if (count_rra_rrb_a(a, b, current) < i)
			i = count_rra_rrb_a(a, b, current);
		if (count_ra_rrb_a(a, b, current) < i)
			i = count_ra_rrb_a(a, b, current);
		if (count_rra_rb_a(a, b, current) < i)
			i = count_rra_rb_a(a, b, current);
		t = t->next;
	}
	return (i);
}

void	fill_a(t_list **a, t_list **b)
{
	int		i;
	t_list	*t;

	while (*b)
	{
		t = *b;
		i = min_action_count_ba(*a, *b);
		while (i >= 0)
		{
			if (i == count_ra_rb_a(*a, *b, *(int *)t->content))
				i = do_ra_rb(a, b, *(int *)t->content, 'b');
			else if (i == count_ra_rrb_a(*a, *b, *(int *)t->content))
				i = do_ra_rrb(a, b, *(int *)t->content, 'b');
			else if (i == count_rra_rrb_a(*a, *b, *(int *)t->content))
				i = do_rra_rrb(a, b, *(int *)t->content, 'b');
			else if (i == count_rra_rb_a(*a, *b, *(int *)t->content))
				i = do_rra_rb(a, b, *(int *)t->content, 'b');
			else
				t = t->next;
		}
	}
}
