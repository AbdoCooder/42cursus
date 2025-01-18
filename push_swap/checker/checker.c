/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:11:03 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/18 11:42:16 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_result(char *str)
{
	if (str)
		ft_printf("%s\n", str);
	exit (1);
}

void	ft_ko(t_list **stack_a, t_list **stack_b, char *op)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	free(op);
	ft_error(NULL);
}

void	ft_read_and_update(t_list **stack_a, t_list **stack_b)
{
	char	*op;
	int		ok;

	op = get_next_line(0);
	ok = 1;
	while (op)
	{
		ok = ft_check_swap(stack_a, stack_b, op);
		if (ok == 0)
		{
			ok = ft_check_rotate(stack_a, stack_b, op);
			if (ok == 0)
			{
				ok = ft_check_push(stack_a, stack_b, op);
				if (ok == 0)
					ft_ko(stack_a, stack_b, op);
			}
		}
		op = get_next_line(0);
	}
}

void	ft_checker(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b != NULL || !stack_sorted(*stack_a))
	{
		ft_lstclear(stack_a, free);
		ft_lstclear(stack_b, free);
		ft_result("KO\n");
	}
	else
	{
		ft_lstclear(stack_a, free);
		ft_lstclear(stack_b, free);
		ft_result("OK\n");
	}
}

int	main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			len;
	int			i;
	int			check;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (ft_check_args_valid(argc, argv) == 1)
		return (ft_error(NULL), 1);
	while (argv[i])
	{
		len = 0;
		check = ft_create_stack(&argv, &stack_a, i, len);
		if (check == 1)
			return (ft_error(NULL), 1);
		i++;
	}
	ft_read_and_update(&stack_a, &stack_b);
	ft_checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
