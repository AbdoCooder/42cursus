/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:17:13 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/28 10:36:11 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list *a)
{
	int		i;

	i = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content < i)
			i = *(int *)a->content;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_list *a)
{
	int		i;

	i = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content > i)
			i = *(int *)a->content;
		a = a->next;
	}
	return (i);
}

int	ft_sorted(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->next != NULL && (*(int *)(tmp->next)->content) < *(int *)(tmp->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*stack)->content;
	b = *(int *)(*stack)->next->content;
	c = *(int *)(*stack)->next->next->content;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
		(sa(stack), rra(stack));
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
		(sa(stack), ra(stack));
	else if (a < b && b > c && a > c)
		rra(stack);
}
