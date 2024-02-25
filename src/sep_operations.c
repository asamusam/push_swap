/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:33:09 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/24 23:01:08 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack x.
// Do nothing if there is only one or no elements.
void	swap(t_list **x, char s)
{
	void	*temp;

	temp = NULL;
	if (ft_lstsize(*x) >= 2)
	{
		temp = (*x)->content;
		(*x)->content = (*x)->next->content;
		(*x)->next->content = temp;
	}
	if (s != 's')
		ft_printf("%c%c\n", 's', s);
}

// Take the first element at the top of x and put it at the top of y.
// Do nothing if x is empty.
void	push(t_list **x, t_list **y, char s)
{
	t_list	*temp;

	temp = NULL;
	if (*x)
	{
		temp = (*x)->next;
		ft_lstadd_front(y, *x);
		*x = temp;
	}
	ft_printf("%c%c\n", 'p', s);
}

// Shift up all elements of stack x by 1.
// The first element becomes the last one.
void	rotate(t_list **x, char s)
{
	t_list	*temp;

	temp = NULL;
	if (ft_lstsize(*x) >= 2)
	{
		ft_lstadd_back(x, ft_lstnew((*x)->content));
		temp = (*x)->next;
		free(*x);
		*x = temp;
	}
	if (s != 's')
		ft_printf("%c%c\n", 'r', s);
}

// Shift down all elements of stack x by 1.
// The last element becomes the first one.
void	rrotate(t_list **x, char s)
{
	t_list	*temp;
	t_list	*last;

	temp = NULL;
	last = NULL;
	if (ft_lstsize(*x) >= 2)
	{
		temp = *x;
		last = ft_lstlast(*x);
		while (temp->next && temp->next != last)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(x, last);
	}
	if (s != 's')
		ft_printf("%c%c%c\n", 'r', 'r', s);
}
