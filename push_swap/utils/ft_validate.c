/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:36:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/14 22:18:02 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_args_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j])
				&& !(argv[i][j] == '-' || argv[i][j] == '+'
				|| argv[i][j] == ' ' || argv[i][j] == '\t'))
				|| (argv[i][j] == '\0'))
				return (1);
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (!argv[i][j + 1] || !ft_isdigit(argv[i][j + 1]))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
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

void	ft_error(char *str)
{
	write(2, "Error\n", 6);
	if (str)
		ft_printf("%s\n", str);
	exit (1);
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
