/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:09:17 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/26 16:58:51 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_zero(char *s)
{
	if (*s == '+' || *s == '-')
		s ++;
	while (*s)
	{
		if (*s != '0')
			return (false);
		s ++;
	}
	return (true);
}

static bool	parse_element(char *el, t_list **a)
{
	int	*num;

	num = malloc(sizeof(int));
	if (!num)
	{
		ft_printf("%s\n", "Malloc failed");
		return (false);
	}
	*num = ft_atoi_mod(el);
	if (*num == 0 && !check_zero(el))
	{
		free(num);
		return (false);
	}
	if (!ft_lstadd_back_mod(a, ft_lstnew(num)))
	{
		free(num);
		return (false);
	}
	return (true);
}

bool	parse_input(char **av, t_list **a)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!parse_element(split[j], a))
			{
				free(split[j]);
				free(split);
				return (false);
			}
			free(split[j]);
			j ++;
		}
		free(split);
		i ++;
	}
	return (true);
}
