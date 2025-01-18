/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:11:40 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/18 11:43:21 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "get_next_line_bonus/get_next_line_bonus.h"

int	ft_strcmp(const char *s1, const char *s2);
int	ft_check_swap(t_list **stack_a, t_list **stack_b, char *op);
int	ft_check_rotate(t_list **stack_a, t_list **stack_b, char *op);
int	ft_check_push(t_list **stack_a, t_list **stack_b, char *op);

#endif
