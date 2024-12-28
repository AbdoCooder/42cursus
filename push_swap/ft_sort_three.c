/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:17:13 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/28 11:06:09 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	if (ft_lstsize(*stack) != 3)
		ft_error("stack size is not 3 --ft_sort_three.c");
	a = *(int *)(*stack)->content;
	b = *(int *)(*stack)->next->content;
	c = *(int *)(*stack)->next->next->content;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
		(sa(stack), rra(stack));
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
		(sa(stack), ra(stack));
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	ft_sort_two(t_list **stack)
{
	int	a;
	int	b;

	if (ft_lstsize(*stack) != 2)
		ft_error("stack size is not 2 | --ft_sort_three.c/ft_sort_two()");
	a = *(int *)(*stack)->content;
	b = *(int *)(*stack)->next->content;
	if (a > b)
		sa(stack);
}
