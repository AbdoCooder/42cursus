/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:45:32 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/14 22:32:46 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_find_node(int number, t_list *stack)
{
	while (stack)
	{
		if (*(int *)stack->content == number)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_find_target_in_a(t_list **ptr, t_list **stack_a)
{
	t_list	*node;
	t_list	*closest_bigger;

	closest_bigger = NULL;
	node = *stack_a;
	while (node)
	{
		if (*(int *)node->content > *(int *)(*ptr)->content)
		{
			if (!closest_bigger
				|| (*(int *)node->content < *(int *)closest_bigger->content))
				closest_bigger = node;
		}
		node = node->next;
	}
	if (!closest_bigger)
		closest_bigger = ft_find_node(ft_min(*stack_a), *stack_a);
	(*ptr)->target = closest_bigger;
}

t_list	*ft_find_cheapest(t_list **stack)
{
	t_list	*cheapest;

	cheapest = *stack;
	ft_set_push_cost(stack);
	cheapest = ft_find_node(ft_min_push_cost(*stack), *stack);
	return (cheapest);
}

int	ft_min_push_cost(t_list *stack)
{
	int		min;
	int		number;
	t_list	*ptr;

	if (!stack)
		ft_error(NULL);
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

void	ft_finish(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		ft_prepare(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	ft_set_indexs(stack_a, stack_b);
	ft_move_top(stack_a, ft_find_node(ft_min(*stack_a), *stack_a));
}
