/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:30 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/14 16:13:24 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_optimization(t_list **stack_a, t_list **stack_b, t_list	**cheapest)
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

static void	ft_prepare(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	ft_refresh(stack_a, stack_b);
	cheapest = ft_find_cheapest(stack_b);
	ft_optimization(stack_b, stack_a, &cheapest);
	ft_refresh(stack_a, stack_b);
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
	// ft_refresh(stack_a, stack_b);
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

int ft_b_move_mr(t_list **stack_a ,int medium)
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
	ptr = *stack_a;
	int medium = ft_sum(*stack_a) / ft_lstsize(*stack_a);
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
	{
		while (ptr && ft_lstsize(*stack_a) > 3)
		{
			int data = ft_b_move_mr(stack_a,medium);
			ft_move_top(stack_a, ft_find_node(data, *stack_a));
			pb(stack_a, stack_b);
			ft_set_upper(stack_a);
			ptr = *stack_a;
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
