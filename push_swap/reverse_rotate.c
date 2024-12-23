/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:09:35 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/23 13:07:25 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*ptr;
	t_list	*tmp;

	if (*stack == NULL || ft_lstsize(*stack) <= 1)
		return ;
	ptr = *stack;
	tmp = ptr->next;
	while(tmp != NULL && tmp->next != NULL && ptr != NULL)
		tmp = tmp->next;
	*stack = ptr->next;
	ptr->next = NULL;
	tmp->next = ptr;
}
void	rra(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}
void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
