/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:45:32 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/14 16:13:47 by abenajib         ###   ########.fr       */
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

void	ft_find_target_in_b(t_list **ptr, t_list **stack_b)
{
	t_list	*node;
	node = *stack_b;

	(*ptr)->target = NULL;
	while (node)
	{
		if (((*(int *)node->content) < (*(int *)(*ptr)->content))
			&& ((*ptr)->target == NULL
			|| (*(int *)node->content) > (*(int *)(*ptr)->target)))
		{
			(*ptr)->target = node;
		}
		node = node->next;
	}
	if ((*ptr)->target == NULL)
		(*ptr)->target = ft_find_node(ft_max(*stack_b), *stack_b);
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
			if (!closest_bigger || (*(int *)node->content < *(int *)closest_bigger->content))
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
