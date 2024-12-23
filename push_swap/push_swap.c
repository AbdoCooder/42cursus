/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:44:19 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/23 14:54:51 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("\n===========\n");
	ft_printf("stack_a\n");
	if (!stack_a)
		ft_printf("EMPTY!\n");
	while (stack_a)
	{
		ft_printf(" ---\n");
		ft_printf("| %d |\n", *(int *)(stack_a->content));
		ft_printf(" --- \n");
		stack_a = stack_a->next;
	}
	ft_printf("===========\n");
	ft_printf("stack_b\n");
	if (!stack_b)
		ft_printf("EMPTY!\n");
	while (stack_b)
	{
		ft_printf(" ---\n");
		ft_printf("| %d |\n", *(int *)(stack_b->content));
		ft_printf(" ---\n");
		stack_b=stack_b->next;
	}
}

int	check_args_valid(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if(!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char* argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	if(check_args_valid(argc, argv) == -1)
	{
		write(2, "ERROR\n", 6);
		return (-1);
	}
	if (argc == 2)
	{
		len = 0;
		split = ft_split(*(argv + 1), " \t");
		while (split[len] != NULL)
		{
			int *new = malloc(4);
			*new = ft_atoi(split[len]);
			ft_lstadd_back(&stack_a, ft_lstnew(new));
			len++;
		}
	}
	else
	{
		len = 1;
		while (len < argc)
		{
			int *new = malloc(4);
			*new = ft_atoi(argv[len]);
			ft_lstadd_back(&stack_a, ft_lstnew(new));
			len++;
		}
	}
	ft_print_stacks(stack_a, stack_b);
	return (0);
}
