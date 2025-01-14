/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:50:31 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/14 16:14:14 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_refresh(t_list **stack_a, t_list **stack_b)
{
	ft_set_indexs(stack_a, stack_b);
	ft_set_costs(stack_a, stack_b);
	ft_set_targets(stack_a, stack_b);
	ft_set_upper(stack_a);
	ft_set_upper(stack_b);
}

int	ft_min_push_cost(t_list *stack)
{
	if (!stack)
		ft_error("empty stack -- ft_min_push_cost");
	int		min;
	int		number;
	t_list	*ptr;

	min = stack->push_cost;
	number = *(int *)stack->content;
	ptr = stack;
	while (ptr)
	{
		if (ptr->push_cost < min)
		{
			number = *(int *)ptr->content;
			min = ptr->push_cost;
		}
		ptr = ptr->next;
	}
	return (number);
}
