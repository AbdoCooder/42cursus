/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:30 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/29 18:50:27 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_list *node;
	t_list *closest_bigger = NULL;

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

void	ft_set_costs(t_list **stack_a)
{

}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		counter;
	t_list	*ptr;

	counter = 0;
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
	{
		while (ft_lstsize(*stack_a) > 3 && counter++ < 2)
			pb(stack_a, stack_b);
		ptr = *stack_a;
		while (ptr)
		{
			ft_find_target_in_b(&ptr, stack_b);
			ptr = ptr->next;
		}
		while (ft_lstsize(*stack_a) > 3)
		{
		// 	ft_set_costs(stack_a);
		// 	ft_move_cheapest(stack_a, stack_b);
		}
		ft_sort_three(stack_a);
		ptr = *stack_b;
		while (ptr)
		{
			ft_find_target_in_a(&ptr, stack_a);
			ptr = ptr->next;
		}
	}
}
// ft_printf("|%d|-->|%d|\n",  *(int *)ptr->content, *(int *)(ptr->target)->content);
