/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:00:30 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/04 16:28:45 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_node(int number, t_list *stack)
{
	while (stack)
	{
		if (*(int *)stack->content == number)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_find_target_in_b(t_list **ptr, t_list **stack_b)
{
	t_list	*node;

	node = *stack_b;
	(*ptr)->target = NULL;
	while (node)
	{
		if (((*(int *)node->content) < (*(int *)(*ptr)->content))
			&& ((*ptr)->target == NULL
			|| (*(int *)node->content) > (*(int *)(*ptr)->target)))
		{
			(*ptr)->target = node;
		}
		node = node->next;
	}
	if ((*ptr)->target == NULL)
		(*ptr)->target = ft_find_node(ft_max(*stack_b), *stack_b);
}

void	ft_find_target_in_a(t_list **ptr, t_list **stack_a)
{
	t_list *node;
	t_list *closest_bigger = NULL;

	node = *stack_a;
	while (node)
	{
		if (*(int *)node->content > *(int *)(*ptr)->content)
		{
			if (!closest_bigger || (*(int *)node->content < *(int *)closest_bigger->content))
				closest_bigger = node;
		}
		node = node->next;
	}
	if (!closest_bigger)
		closest_bigger = ft_find_node(ft_min(*stack_a), *stack_a);
	(*ptr)->target = closest_bigger;
}

t_list	*ft_find_cheapest(t_list **stack)
{
	t_list	*cheapest;
	t_list	*ptr;

	cheapest = *stack;
	ptr = *stack;
	while (ptr)
	{
		if ((ptr->cost + ptr->target->cost) < (cheapest->cost + cheapest->target->cost))
			cheapest = ptr;
		ptr = ptr->next;
	}
	return (cheapest);
}

void	ft_set_indexs(t_list **stack_a, t_list **stack_b)
{
	int	i;
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

	ft_set_indexs(stack_a, stack_b);//refresh the indexs to it correct values
	middle = ft_lstsize(*stack_a) / 2;
	ptr = *stack_a;
	while (ptr)//loop on a and set cost for each node
	{
		if (ptr->index <= middle)
			ptr->cost = ptr->index;
		else
			ptr->cost = ft_lstsize(*stack_a) - ptr->index;
		ptr = ptr->next;
	}
	ptr = *stack_b;
	middle = ft_sum(*stack_b) / ft_lstsize(*stack_b);
	while (ptr)//loop on b and set cost for each node
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
	while (ptr)//loop on stack and set upper true for each node above the median
	{
		if (ptr->index <= middle)
			ptr->upper = true;
		else
			ptr->upper = false;
		ptr = ptr->next;
	}
}

void	ft_move_cheapest_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest(stack_a);
	// ft_printf("cheapest is [%d]\n", *(int *)cheapest->content);
	ft_set_upper(stack_a);//set upper true for each node above the median
	ft_set_upper(stack_b);
	while (*stack_a != cheapest)
	{
		if ((*stack_a)->upper == true)
			ra(stack_a);
		else
			rra(stack_a);
	}
	while (*stack_b != cheapest->target)
	{
		if ((*stack_b)->upper == true)// it was [(*stack)->target->upper] and caused a segfault
			rb(stack_b);
		else
			rrb(stack_b);
	}
	// ft_set_indexs(stack_a, stack_b);
	// ft_printf("cheapest_index: %d \n", (cheapest)->index);
	// ft_printf("cheapest_target_index: %d \n", (cheapest->target)->index);
	pb(stack_a, stack_b);
}

void	ft_move_cheapest_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = ft_find_cheapest(stack_b);
	ft_set_upper(stack_a);
	ft_set_upper(stack_b);
	while (*stack_a != cheapest->target)
	{
		if (cheapest->target->upper == true)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pa(stack_a, stack_b);
}

void ft_print_info(t_list *stack_a, t_list *stack_b)
{
	ft_printf("stack_a\n");
	while (stack_a)
	{
		ft_printf("index: %d | [%d] --> [%d] | cost : %d | upper? %s\n", (stack_a)->index, *(int *)(stack_a)->content, *(int *)((stack_a)->target)->content, (stack_a)->cost, (stack_a)->upper ? "yes" : "no");
		stack_a = stack_a->next;
	}
	ft_printf("stack_b\n");
	while (stack_b)
	{
		ft_printf("index: %d | [%d] --> [%d] | cost : %d | upper? %s\n", (stack_b)->index, *(int *)(stack_b)->content, *(int *)((stack_b)->target)->content, (stack_b)->cost, (stack_b)->upper ? "yes" : "no");
		stack_b = stack_b->next;
	}
}

void	ft_min_on_top(t_list **a)
{
	while (*(int *)(*a)->content != *(int *)(ft_find_node(ft_min(*a), *a)->content))
	{
		if (ft_find_node(ft_min(*a), *a)->upper == true)
			ra(a);
		else
			rra(a);
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
		while (ptr)// after this loop every node on a has a target in b
		{
			ft_find_target_in_b(&ptr, stack_b);
			ptr = ptr->next;
		}
		while (ft_lstsize(*stack_a) > 3) // move the cheapest node to b until still three in a
		{
			ft_set_costs(stack_a, stack_b);
			ft_move_cheapest_to_b(stack_a, stack_b);
		}
		ft_sort_three(stack_a);
		ptr = *stack_b;
		while (ptr)// after this loop every node on b has a target in a
		{
			ft_find_target_in_a(&ptr, stack_a);
			ptr = ptr->next;
		}
		while (*stack_b) // move the cheapest node to a until still nothing in b
		{
			ft_set_costs(stack_a, stack_b);
			ft_move_cheapest_to_a(stack_a, stack_b);
		}
		ft_set_indexs(stack_a, stack_b);
		ft_min_on_top(stack_a);
	}
}
//ft_printf("index: %d | [%d] --> [%d] | cost : %d | upper? %s\n", (*stack_a)->index, *(int *)(*stack_a)->content, *(int *)((*stack_a)->target)->content, (*stack_a)->cost, (*stack_a)->upper ? "yes" : "no");
