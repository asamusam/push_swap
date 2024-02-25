/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:46:53 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/24 23:19:04 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get maximum number in a stack
int	ft_max(t_list *s)
{
	int	i;

	i = *(int *)s->content;
	while (s)
	{
		if (*(int *)s->content > i)
			i = *(int *)s->content;
		s = s->next;
	}
	return (i);
}

// get minimum number in a stack
int	ft_min(t_list *s)
{
	int	i;

	i = *(int *)s->content;
	while (s)
	{
		if (*(int *)s->content < i)
			i = *(int *)s->content;
		s = s->next;
	}
	return (i);
}

// get current index of a number in a stack
int	get_index(t_list *s, int n)
{
	int	i;

	i = 0;
	while (*(int *)s->content != n)
	{
		s = s->next;
		i ++;
	}
	return (i);
}

// get target index of a number in stack a
int	get_target_index_a(t_list *a, int n)
{
	int		i;
	t_list	*t;

	i = 1;
	if (n < *(int *)a->content && n > *(int *)ft_lstlast(a)->content)
		i = 0;
	else if (n > ft_max(a) || n < ft_min(a))
		i = get_index(a, ft_min(a));
	else
	{
		t = a->next;
		while (n < *(int *)a->content || n > *(int *)t->content)
		{
			a = a->next;
			t = a->next;
			i++;
		}
	}
	return (i);
}

// get target index of a number in stack b
int	get_target_index_b(t_list *b, int n)
{
	int		i;
	t_list	*t;

	i = 1;
	if (n > *(int *)b->content && n < *(int *)ft_lstlast(b)->content)
		i = 0;
	else if (n > ft_max(b) || n < ft_min(b))
		i = get_index(b, ft_max(b));
	else
	{
		t = b->next;
		while (n > *(int *)b->content || n < *(int *)t->content)
		{
			b = b->next;
			t = b->next;
			i++;
		}
	}
	return (i);
}
