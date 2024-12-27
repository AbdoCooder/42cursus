/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:44:19 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/23 18:04:36 by abenajib         ###   ########.fr       */
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


int ft_check_args_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == ' ' || argv[i][j] == '\t'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	ft_isduplicated(t_list **stack, long long new)
{
	t_list *ptr;

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

int	main(int argc, char* argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split;
	int		len;
	int		i;
	long long		*new;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0]=='\0'))
		return (1);
	if(ft_check_args_valid(argc, argv) == 1)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	while (argv[i])
	{
		len = 0;
		split = ft_split(*(argv + i), " \t");

		while(split[len])
		{
			new = malloc(sizeof(long long));
			*new = ft_atoi(split[len]);
			if(ft_isduplicated(&stack_a, *new) == 1)
				return (ft_lstclear(&stack_a, free), free(split), write(2, "ERROR\n", 6), 1);
			ft_lstadd_back(&stack_a, ft_lstnew(new));
			len++;
		}
		free(split);
		i++;
	}

	ft_print_stacks(stack_a, stack_b);
	return (0);
}
