/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:33:09 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/24 23:31:19 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	swap(a, 's');
	swap(b, 's');
	ft_printf("%s\n", "ss");
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, 's');
	rotate(b, 's');
	ft_printf("%s\n", "rr");
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a, 's');
	rrotate(b, 's');
	ft_printf("%s\n", "rrr");
}
