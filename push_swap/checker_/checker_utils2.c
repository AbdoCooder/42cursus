/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:06:35 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/18 11:41:46 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		ft_error(NULL);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || sign * result < INT_MIN)
			return (result * sign);
		str++;
	}
	if (*str != '\0')
		ft_error(NULL);
	return (result * sign);
}

int	ft_isduplicated(t_list **stack, long long new)
{
	t_list	*ptr;

	ptr = *stack;
	if (new > INT_MAX || new < INT_MIN)
		return (1);
	while (ptr)
	{
		if (*(long long *)ptr->content == new)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	ft_check_swap(t_list **stack_a, t_list **stack_b, char *op)
{
	int	ok;

	ok = 1;
	if (ft_strcmp(op, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(op, "ss\n") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
		ok = 0;
	return (ok);
}

int	ft_check_rotate(t_list **stack_a, t_list **stack_b, char *op)
{
	int	ok;

	ok = 1;
	if (ft_strcmp(op, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(op, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(op, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(op, "rrr\n") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		ok = 0;
	return (ok);
}
