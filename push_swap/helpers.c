/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:50:31 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/04 16:27:16 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

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
