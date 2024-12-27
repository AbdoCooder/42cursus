/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:17:13 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/27 22:51:06 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list *a)
{
	int		i;

	i = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content < i)
			i = *(int *)a->content;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_list *a)
{
	int		i;

	i = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content > i)
			i = *(int *)a->content;
		a = a->next;
	}
	return (i);
}

int	ft_sorted(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->next != NULL && (*(int *)(tmp->next)->content) < *(int *)(tmp->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_three(t_list **stack)
{
	if (ft_lstsize(*stack) != 3)
		return (write(2, "Stack size not 3 !!\n", 20), exit(1));
	if (!ft_sorted(*stack))
	{
		if((*(int *)(*stack)->content) == ft_max(*stack))
		{
			ra(stack);
			if (!ft_sorted(*stack))
				sa(stack);
		}
		else if ((*(int *)(*stack)->content) == ft_min(*stack))
		{
			rra(stack);
			sa(stack);
		}
		else
		{
			sa(stack);
			if (!ft_sorted(*stack))
			{
				rra(stack);
				sa(stack);
				ra(stack);
			}
		}
	}
}
