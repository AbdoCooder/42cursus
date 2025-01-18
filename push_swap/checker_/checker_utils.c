/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:35:22 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/18 16:19:23 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_error(char *str)
{
	write(2, "Error\n", 6);
	if (str)
		ft_printf("%s\n", str);
	exit (1);
}

int	ft_create_stack(char **argv[], t_list **stack_a, int i, int len)
{
	char		**split;
	long long	*new;

	split = ft_split(*(*argv + i), " \t");
	if (!*split || !split)
		return (ft_error(NULL), 1);
	while (split[len])
	{
		new = malloc(sizeof(long long));
		*new = ft_atoi(split[len]);
		if (ft_isduplicated(stack_a, *new) == 1)
			return (ft_lstclear(stack_a, free), free(split), ft_error(NULL), 1);
		ft_lstadd_back(stack_a, ft_lstnew(new));
		free(split[len]);
		len++;
	}
	free(split);
	return (0);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
