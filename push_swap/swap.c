/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:53:47 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/27 18:22:36 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*ptr;
	t_list	*tmp;

	if (*stack != NULL && (*stack)->next == NULL)
		return ;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		ptr = *stack;
		tmp = ptr->next;
		ptr->next = ptr->next->next;
		tmp->next = ptr;
		*stack = tmp;
	}
}

void	sa(t_list **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_list **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
