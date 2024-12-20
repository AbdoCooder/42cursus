/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdocooder <abdocooder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:42:31 by abenajib          #+#    #+#             */
/*   Updated: 2024/11/06 21:41:34 by abdocooder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*c;

	if (!lst || !f)
		return ;
	c = lst;
	while (c != NULL)
	{
		f(c->content);
		c = c->next;
	}
}
