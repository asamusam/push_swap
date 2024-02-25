/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:38:02 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/24 22:21:17 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count number of steps to place a number into stack b
// with rotating both stacks
int	count_ra_rb(t_list *a, t_list *b, int n)
{
	int	current_index_a;
	int	target_index_b;

	current_index_a = get_index(a, n);
	target_index_b = get_target_index_b(b, n);
	if (current_index_a > target_index_b)
		return (current_index_a);
	return (target_index_b);
}

// count number of steps to place a number into stack b
// with reverse rotating both stacks
int	count_rra_rrb(t_list *a, t_list *b, int n)
{
	int	i;
	int	size_a;
	int	size_b;
	int	current_index_a;
	int	target_index_b;

	i = 0;
	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	current_index_a = get_index(a, n);
	target_index_b = get_target_index_b(b, n);
	if (target_index_b)
		i = size_b - target_index_b;
	if (i < size_a - current_index_a && current_index_a)
		i = size_a - current_index_a;
	return (i);
}

// count number of steps to place a number into stack b
// with rotating stack a and reverse rotating stack b
int	count_ra_rrb(t_list *a, t_list *b, int n)
{
	int	size_b;
	int	current_index_a;
	int	target_index_b;

	size_b = ft_lstsize(b);
	current_index_a = get_index(a, n);
	target_index_b = get_target_index_b(b, n);
	if (target_index_b)
		return (size_b - target_index_b + current_index_a);
	return (current_index_a);
}

// count number of steps to place a number into stack b
// with reverse rotating stack a and rotating stack b
int	count_rra_rb(t_list *a, t_list *b, int n)
{
	int	size_a;
	int	current_index_a;
	int	target_index_b;

	size_a = ft_lstsize(a);
	current_index_a = get_index(a, n);
	target_index_b = get_target_index_b(b, n);
	if (current_index_a)
		return (size_a - current_index_a + target_index_b);
	return (target_index_b);
}
