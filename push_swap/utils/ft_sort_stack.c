/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:30 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/06 22:49:26 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_prepare(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	ft_refresh(stack_a, stack_b);
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
	ft_refresh(stack_a, stack_b);
}

void	ft_optimization(t_list **stack_a, t_list **stack_b, t_list	**cheapest)
{
	while (*stack_a != (*cheapest) && (*cheapest)->target != *stack_b)
	{
		if ((*cheapest)->upper && (*cheapest)->target->upper)
			rr(stack_a, stack_b);
		else if (!((*cheapest)->upper) && !((*cheapest)->target->upper))
			rrr(stack_a, stack_b);
	}
}

void	ft_prep_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	ft_refresh(stack_a, stack_b);
	cheapest = ft_find_cheapest(stack_a);
	// ft_optimization(stack_a, stack_b, &cheapest);
	ft_refresh(stack_a, stack_b);
	while (*stack_a != cheapest)
	{
		if (cheapest->upper == true)
				ra(stack_a);
			else
				rra(stack_a);
	}
	while (*stack_b != cheapest->target)
	{
		if (cheapest->target->upper == true)
				rb(stack_b);
			else
				rrb(stack_b);
	}
	ft_refresh(stack_a, stack_b);
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
	{
		// if (ft_lstsize(*stack_a) > 3)
		// 	pb(stack_a, stack_b);
		// if (ft_lstsize(*stack_a) > 3)
		// 	pb(stack_a, stack_b);
		while (ft_lstsize(*stack_a) > 3)
		{
			// ft_printf("stack a-----%d---------\n", ft_lstsize(*stack_a));
			// ft_prep_move(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		ft_sort_three(stack_a);
		while (*stack_b)
		{
			ft_prepare(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		ft_set_indexs(stack_a, stack_b);
		ft_min_on_top(stack_a);
	}
}
//ft_printf("index: %d | [%d] --> [%d] | cost : %d | upper? %s\n", (*stack_a)->index, *(int *)(*stack_a)->content, *(int *)((*stack_a)->target)->content, (*stack_a)->cost, (*stack_a)->upper ? "yes" : "no");
