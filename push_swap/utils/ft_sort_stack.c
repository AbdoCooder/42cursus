/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:30 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/14 22:34:16 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_optimization(t_list **stack_a, t_list **stack_b, t_list	**cheapest)
{
	while (*stack_a != (*cheapest) && (*cheapest)->target != *stack_b)
	{
		if ((*cheapest)->upper && (*cheapest)->target->upper)
			rr(stack_a, stack_b);
		else if (!((*cheapest)->upper) && !((*cheapest)->target->upper))
			rrr(stack_a, stack_b);
		else
			break ;
	}
}

void	ft_prepare(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	ft_refresh(stack_a, stack_b);
	cheapest = ft_find_cheapest(stack_b);
	ft_optimization(stack_b, stack_a, &cheapest);
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
}

void	ft_move_top(t_list **stack, t_list *ptr)
{
	ft_set_upper(stack);
	while (*stack != ptr)
	{
		if (ptr->upper == true)
			ra(stack);
		else
			rra(stack);
	}
}

int	ft_b_move(t_list **stack_a, int medium)
{
	int		size;
	t_list	*ptr;

	ptr = *stack_a;
	size = ft_lstsize(*stack_a);
	while (ptr)
	{
		if (*(int *)(ptr)->content < medium)
			return (*(int *)(ptr)->content);
		ptr = (ptr)->next;
	}
	return (*(int *)(*stack_a)->content);
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		medium;
	int		data;

	ptr = *stack_a;
	medium = ft_sum(*stack_a) / ft_lstsize(*stack_a);
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
	{
		while (ft_lstsize(*stack_a) > 3)
		{
			data = ft_b_move(stack_a, medium);
			ft_move_top(stack_a, ft_find_node(data, *stack_a));
			pb(stack_a, stack_b);
			ft_set_upper(stack_a);
			ptr = *stack_a;
		}
		ft_sort_three(stack_a);
		ft_finish(stack_a, stack_b);
	}
}
