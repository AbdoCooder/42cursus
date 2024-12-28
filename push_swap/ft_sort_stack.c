/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:30 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/28 13:27:37 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target(t_list *node, t_list **stack_b)
{
	int		max_b;
	t_list	*ptr;

	max_b = ft_max(*stack_b);
	ptr = *stack_b;
	(node)->target = *stack_b;
	while (ptr)
	{
		if ((*(int *)(ptr->content) < *(int *)(node)->content))
			(node)->target = ptr;
		else
			(node)->target = NULL;
		ptr = ptr->next;
	}
	ptr = *stack_b;
	if ((node)->target == NULL)
	{
		while (ptr)
		{
			if (*(int *)(ptr->content) == max_b)
			{
				(node)->target = ptr;
				return ;
			}
			ptr = ptr->next;
		}
	}
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
			ft_find_target(ptr, stack_b);
			if (ptr->target != NULL)
				ft_printf("|%d|-->|%d|\n",  *(int *)ptr->content, *(int *)(ptr->target)->content);
			else
				ft_printf("|%d|-->|max|\n",  *(int *)ptr->content);
			ptr = ptr->next;
		}
	}
}
