/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:09:22 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/18 11:42:27 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	if (!stack || ft_lstsize(*stack) <= 1)
		return ;
	head = *stack;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	*stack = head->next;
	head->next = NULL;
	tmp->next = head;
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(&(*stack_b), tmp);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!stack || ft_lstsize(*stack) <= 1)
		return ;
	ptr = NULL;
	tmp = *stack;
	while (tmp->next)
	{
		ptr = tmp;
		tmp = tmp->next;
	}
	if (ptr)
		ptr->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap(t_list **stack)
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

int	ft_check_push(t_list **stack_a, t_list **stack_b, char *op)
{
	int	ok;

	ok = 1;
	if (ft_strcmp(op, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(op, "pb\n") == 0)
		push(stack_a, stack_b);
	else
		ok = 0;
	return (ok);
}
