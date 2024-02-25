/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:57:22 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/26 17:41:36 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_mod(const char *nptr)
{
	int		neg;
	int		res;
	char	*str;

	str = (char *)nptr;
	res = 0;
	neg = 1;
	while (*str <= ' ')
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str ++;
	}
	while (*str)
	{
		res = res * 10 + (*str - 48);
		if (!ft_isdigit(*str))
			return (0);
		if ((res < 0 && (neg == 1 || (neg == -1 && res != INT_MIN))))
			return (0);
		str ++;
	}
	return (res * neg);
}

t_list	*ft_lstlast_mod(t_list *lst, int *num)
{
	if (!lst || *(int *)lst->content == *num)
		return (NULL);
	while (lst && lst->next)
	{
		if (*(int *)lst->content == *num || *(int *)lst->next->content == *num)
			return (NULL);
		lst = lst->next;
	}
	return (lst);
}

bool	ft_lstadd_back_mod(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!new)
		return (false);
	if (!*lst)
	{
		*lst = new;
		return (true);
	}
	last_node = ft_lstlast_mod(*lst, new->content);
	if (*lst && !last_node)
	{
		free(new);
		return (false);
	}
	last_node->next = new;
	return (true);
}
