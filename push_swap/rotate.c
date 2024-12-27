/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:18:31 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/27 22:50:07 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*ptr;
	t_list	*tmp;

	if (*stack == NULL || ft_lstsize(*stack) <= 1)
		return ;
	ptr = *stack;
	tmp = ptr->next;
	while (tmp != NULL && tmp->next != NULL && ptr != NULL)
	{
		ptr = ptr->next;
		tmp = tmp->next;
	}
	tmp->next = *stack;
	ptr->next = NULL;
	*stack = tmp;
}

void	ra(t_list **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_list **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
