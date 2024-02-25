/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:56:16 by asamuilk          #+#    #+#             */
/*   Updated: 2023/12/26 17:12:06 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

// 1 - sa;
// 2 - sb;
// 3 - ss;
// 4 - pa;
// 5 - pb;
// 6 - ra;
// 7 -	rb;
// 8 - rr;
// 9 - rra;
// 10 - rrb;
// 11 - rrr;

void	print_stack(t_list *x, char s)
{
	ft_printf("stack %c: ", s);
	while (x)
	{
		ft_printf("%d ", *(int *)x->content);
		x = x->next;
	}
	ft_printf("%c", '\n');
}

bool	is_sorted(t_list *a)
{
	t_list	*i;

	i = a;
	while (i->next)
	{
		if (*(int *)i->content > *(int *)i->next->content)
			return (false);
		i = i->next;
	}
	return (true);
}

void	sort_three(t_list **a)
{
	int	x;
	int	y;
	int	z;

	x = *(int *)(*a)->content;
	y = *(int *)(*a)->next->content;
	z = *(int *)(*a)->next->next->content;
	if (x < y && y > z && z > x)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	if (x > y && y < z && z > x)
		swap(a, 'a');
	if (x < y && y > z && z < x)
		rrotate(a, 'a');
	if (x > y && y < z && z < x)
		rotate(a, 'a');
	if (x > y && y > z && z < x)
	{
		swap(a, 'a');
		rrotate(a, 'a');
	}
}

void	sort(t_list **a, t_list **b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (size_a == 2)
		swap(a, 'a');
	else if (size_a == 3)
		sort_three(a);
	else
	{
		fill_b(a, b);
		fill_a(a, b);
		final_sort_a(a);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(av, &a))
	{
		write(STDERR, "Error\n", 6);
		ft_lstclear(&a, &free);
		return (0);
	}
	if (!is_sorted(a))
		sort(&a, &b);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
}
