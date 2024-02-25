/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:55:33 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/25 13:35:50 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count number of steps to place a number into stack a
// with rotating both stacks
int	count_ra_rb_a(t_list *a, t_list *b, int n)
{
	int	target_index_a;
	int	current_index_b;

	target_index_a = get_target_index_a(a, n);
	current_index_b = get_index(b, n);
	if (target_index_a < current_index_b)
		return (current_index_b);
	return (target_index_a);
}

// count number of steps to place a number into stack a
// with reverse rotating both stacks
int	count_rra_rrb_a(t_list *a, t_list *b, int n)
{
	int	i;
	int	target_index_a;
	int	current_index_b;
	int	size_a;
	int	size_b;

	target_index_a = get_target_index_a(a, n);
	current_index_b = get_index(b, n);
	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	i = 0;
	if (target_index_a)
		i = size_a - target_index_a;
	if (current_index_b && i < size_b - current_index_b)
		i = size_b - current_index_b;
	return (i);
}

// count number of steps to place a number into stack a
// with rotating stack a and reverse rotating stack b
int	count_ra_rrb_a(t_list *a, t_list *b, int n)
{
	int	target_index_a;
	int	current_index_b;
	int	size_b;

	target_index_a = get_target_index_a(a, n);
	current_index_b = get_index(b, n);
	size_b = ft_lstsize(b);
	if (current_index_b)
		return (size_b - current_index_b + target_index_a);
	return (target_index_a);
}

// count number of steps to place a number into stack a
// with reverse rotating stack a and rotating stack b
int	count_rra_rb_a(t_list *a, t_list *b, int n)
{
	int	target_index_a;
	int	current_index_b;
	int	size_a;

	target_index_a = get_target_index_a(a, n);
	current_index_b = get_index(b, n);
	size_a = ft_lstsize(a);
	if (target_index_a)
		return (size_a - target_index_a + current_index_b);
	return (current_index_b);
}
