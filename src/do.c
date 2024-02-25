/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:41:30 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/24 23:30:01 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push a number to a stack
// with rotating both stacks
int	do_ra_rb(t_list **a, t_list **b, int n, char s)
{
	if (s == 'a')
	{
		while (*(int *)(*a)->content != n && get_target_index_b(*b, n) > 0)
			rr(a, b);
		while (*(int *)(*a)->content != n)
			rotate(a, 'a');
		while (get_target_index_b(*b, n) > 0)
			rotate(b, 'b');
		push(a, b, 'b');
	}
	else
	{
		while (*(int *)(*b)->content != n && get_target_index_a(*a, n) > 0)
			rr(a, b);
		while (*(int *)(*b)->content != n)
			rotate(b, 'b');
		while (get_target_index_a(*a, n) > 0)
			rotate(a, 'a');
		push(b, a, 'a');
	}
	return (-1);
}

// push a number to a stack
// with reverse rotating both stacks
int	do_rra_rrb(t_list **a, t_list **b, int n, char s)
{
	if (s == 'a')
	{
		while (*(int *)(*a)->content != n && get_target_index_b(*b, n) > 0)
			rrr(a, b);
		while (*(int *)(*a)->content != n)
			rrotate(a, 'a');
		while (get_target_index_b(*b, n) > 0)
			rrotate(b, 'b');
		push(a, b, 'b');
	}
	else
	{
		while (*(int *)(*b)->content != n && get_target_index_a(*a, n) > 0)
			rrr(a, b);
		while (*(int *)(*b)->content != n)
			rrotate(b, 'b');
		while (get_target_index_a(*a, n) > 0)
			rrotate(a, 'a');
		push(b, a, 'a');
	}
	return (-1);
}

// push a number to a stack
// with rotating a and reverse rotating b
int	do_ra_rrb(t_list **a, t_list **b, int n, char s)
{
	if (s == 'a')
	{
		while (*(int *)(*a)->content != n)
			rotate(a, 'a');
		while (get_target_index_b(*b, n) > 0)
			rrotate(b, 'b');
		push(a, b, 'b');
	}
	else
	{
		while (get_target_index_a(*a, n) > 0)
			rotate(a, 'a');
		while (*(int *)(*b)->content != n)
			rrotate(b, 'b');
		push(b, a, 'a');
	}
	return (-1);
}

// push a number to a stack
// with reverse rotating a and rotating b
int	do_rra_rb(t_list **a, t_list **b, int n, char s)
{
	if (s == 'a')
	{
		while (*(int *)(*a)->content != n)
			rrotate(a, 'a');
		while (get_target_index_b(*b, n) > 0)
			rotate(b, 'b');
		push(a, b, 'b');
	}
	else
	{
		while (get_target_index_a(*a, n) > 0)
			rrotate(a, 'a');
		while (*(int *)(*b)->content != n)
			rotate(b, 'b');
		push(b, a, 'a');
	}
	return (-1);
}
