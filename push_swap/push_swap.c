/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:44:19 by abenajib          #+#    #+#             */
/*   Updated: 2024/12/23 13:38:16 by abenajib         ###   ########.fr       */
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

int	main(int argc, char* argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	len = 0;
	stack_a = NULL;
	stack_b = NULL;
	char **split;
	if (argc == 2)
	{
		split = ft_split(*argv, ' ');
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

	// sa(&stack_a);
	// sb(&stack_b);
	// ss(&stack_a, &stack_b);

	//pa(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);

	// ra(&stack_a);
	// rb(&stack_b);
	// rr(&stack_a, &stack_b);

	// rra(&stack_a);
	// rrb(&stack_b);
	// rrr(&stack_a, &stack_b);

	ft_print_stacks(stack_a, stack_b);
	return (0);
}
