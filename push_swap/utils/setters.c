/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:32 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/14 22:08:06 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_indexs(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = *stack_a;
	while (ptr)
	{
		ptr->index = i;
		i++;
		ptr = ptr->next;
	}
	i = 0;
	ptr = *stack_b;
	while (ptr)
	{
		ptr->index = i;
		i++;
		ptr = ptr->next;
	}
}

void	ft_set_costs(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		middle;

	ft_set_indexs(stack_a, stack_b);
	middle = ft_lstsize(*stack_a) / 2;
	ptr = *stack_a;
	while (ptr)
	{
		if (ptr->index <= middle)
			ptr->cost = ptr->index;
		else
			ptr->cost = ft_lstsize(*stack_a) - ptr->index;
		ptr = ptr->next;
	}
	ptr = *stack_b;
	middle = ft_lstsize(*stack_b) / 2;
	while (ptr)
	{
		if (ptr->index <= middle)
			ptr->cost = ptr->index;
		else
			ptr->cost = ft_lstsize(*stack_b) - ptr->index;
		ptr = ptr->next;
	}
}

void	ft_set_upper(t_list **stack)
{
	t_list	*ptr;
	int		middle;

	if (!(*stack))
		return ;
	middle = ft_lstsize(*stack) / 2;
	ptr = *stack;
	while (ptr)
	{
		if (ptr->index <= middle)
			ptr->upper = true;
		else
			ptr->upper = false;
		ptr = ptr->next;
	}
}

void	ft_set_targets(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;

	ptr = *stack_b;
	while (ptr)
	{
		ft_find_target_in_a(&ptr, stack_a);
		ptr = ptr->next;
	}
}

void	ft_set_push_cost(t_list **stack_a)
{
	t_list	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		if ((ptr->upper && ptr->target->upper)
			|| (!ptr->upper && !ptr->target->upper))
			ptr->push_cost = max(ptr->cost, ptr->target->cost);
		else
			ptr->push_cost = ptr->cost + ptr->target->cost;
		ptr = ptr->next;
	}
}
