/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:30 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/04 16:49:45 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_cheapest_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest(stack_a);
	ft_set_upper(stack_a);
	ft_set_upper(stack_b);
	while (*stack_a != cheapest)
	{
		if ((*stack_a)->upper == true)
			ra(stack_a);
		else
			rra(stack_a);
	}
	while (*stack_b != cheapest->target)
	{
		if ((*stack_b)->upper == true)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	pb(stack_a, stack_b);
}

void	ft_move_cheapest_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest(stack_b);
	ft_set_upper(stack_a);
	ft_set_upper(stack_b);
	while (*stack_a != cheapest->target)
	{
		if (cheapest->target->upper == true)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pa(stack_a, stack_b);
}

void	ft_set_targets(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		ft_find_target_in_b(&ptr, stack_b);
		ptr = ptr->next;
	}
	ptr = *stack_b;
	while (ptr)
	{
		ft_find_target_in_a(&ptr, stack_a);
		ptr = ptr->next;
	}
}

void	ft_prepare(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	ft_set_indexs(stack_a, stack_b);
	ft_set_costs(stack_a, stack_b);
	ft_set_targets(stack_a, stack_b);
	cheapest = ft_find_cheapest(stack_b);
	while (*stack_b != cheapest)
	{
		if (cheapest->upper == true)
				rb(stack_b);
			else
				rrb(stack_b);
	}
	while (*stack_a != cheapest->target)
	{
		if (cheapest->target->upper == true)
				ra(stack_a);
			else
				rra(stack_a);
	}
	ft_set_indexs(stack_a, stack_b);
	ft_set_costs(stack_a, stack_b);
	ft_set_targets(stack_a, stack_b);
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
	{
		while (ft_lstsize(*stack_a) > 3)
			pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		while (*stack_b)
		{
			ft_prepare(stack_a, stack_b); // set the cheapest node with the target at the top
			pa(stack_a, stack_b);
		}
		ft_set_indexs(stack_a, stack_b);
		ft_min_on_top(stack_a);
	}
}
//ft_printf("index: %d | [%d] --> [%d] | cost : %d | upper? %s\n", (*stack_a)->index, *(int *)(*stack_a)->content, *(int *)((*stack_a)->target)->content, (*stack_a)->cost, (*stack_a)->upper ? "yes" : "no");
