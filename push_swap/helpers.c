/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:50:31 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/04 16:53:22 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list *a)
{
	int		i;

	if (!a->next)
		return (*(int *)a->content);
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

	if (!a->next)
		return (*(int *)a->content);
	i = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content > i)
			i = *(int *)a->content;
		a = a->next;
	}
	return (i);
}

int	ft_sum(t_list *stack)
{
	int		sum;
	t_list	*current;

	if (!stack->next)
		return (*(int *)stack->content);
	sum = 0;
	current = stack;
	while (current)
	{
		sum += *(int *)current->content;
		current = current->next;
	}
	return (sum);
}

void	ft_min_on_top(t_list **a)
{
	while (*(int *)(*a)->content
		!= *(int *)(ft_find_node(ft_min(*a), *a)->content))
	{
		if (ft_find_node(ft_min(*a), *a)->upper == true)
			ra(a);
		else
			rra(a);
	}
}
