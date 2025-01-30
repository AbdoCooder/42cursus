/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:44:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/30 21:12:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_stack(char **argv[], t_list **stack_a, int i, int len)
{
	char		**split;
	long long	*new;
	size_t		words;

	words = countwords(*(*argv + i), " \t");
	split = ft_split(*(*argv + i), " \t");
	if (!split || !*split)
		return (free(split), ft_error(NULL), 1);
	while (split[len])
	{
		new = malloc(sizeof(long long));
		*new = ft_atoi(split[len]);
		if (ft_isduplicated(stack_a, *new) == 1)
			return (ft_lstclear(stack_a, free),
				freeall(split, words), ft_error(NULL), 1);
		ft_lstadd_back(stack_a, ft_lstnew(new));
		len++;
	}
	freeall(split, words);
	return (0);
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
			return (ft_lstclear(&stack_a, free), ft_error(NULL), 1);
		i++;
	}
	if (!stack_sorted(stack_a))
		ft_sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}

// ft_print_stacks(stack_a, stack_b);
// void	ft_print_stacks(t_list *stack_a, t_list *stack_b)
// {
// 	ft_printf("\n===========\n");
// 	ft_printf("stack_a\n");
// 	if (!stack_a)
// 		ft_printf("EMPTY!\n");
// 	while (stack_a)
// 	{
// 		ft_printf(" ---\n");
// 		ft_printf("| %d |\n", *(int *)(stack_a->content));
// 		ft_printf(" --- \n");
// 		stack_a = stack_a->next;
// 	}
// 	ft_printf("===========\n");
// 	ft_printf("stack_b\n");
// 	if (!stack_b)
// 		ft_printf("EMPTY!\n");
// 	while (stack_b)
// 	{
// 		ft_printf(" ---\n");
// 		ft_printf("i = %d | %d |cost node %d |target %d
//| cost target %d |cost push %d |\n",
// 				stack_b->index, *(int *)(stack_b->content),
// 				stack_b->cost, *(int *)(stack_b->target->content),
// 				stack_b->target->cost,stack_b->push_cost);
// 		ft_printf(" ---\n");
// 		stack_b = stack_b->next;
// 	}
// }
