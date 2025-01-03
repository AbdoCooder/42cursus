/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:50:31 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/31 20:15:13 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_sorted(t_list *a)
// {
// 	t_list	*tmp;

// 	tmp = a;
// 	while (tmp)
// 	{
// 		if (tmp->next != NULL
// 			&& (*(int *)(tmp->next)->content) < *(int *)(tmp->content))
// 			return (0);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

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
