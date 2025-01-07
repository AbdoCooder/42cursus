/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:51:21 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/07 13:03:30 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
long long	ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(const char *s, char *c);
//list
typedef struct s_list
{
	void			*content;
	int				cost;
	int				push_cost;
	int				index;
	bool			upper;
	struct s_list	*next;
	struct s_list	*target;
}	t_list;
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
//printf
int			ft_printf(const char *str, ...);
int			ft_putstr_fd_p(char *s, int fd);
int			ft_putchar_fd_p(char c, int fd);
int			ft_putnbr_fd_p(int n, int fd);
int			ft_puthex_p(unsigned long long num, char c);
int			ft_putunint_fd_p(unsigned int nb, int fd);
//operations
void		sa(t_list **stack);
void		sb(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack);
void		rb(t_list **stack);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack);
void		rrb(t_list **stack);
void		rrr(t_list **stack_a, t_list **stack_b);
//helpers
int			ft_check_args_valid(int argc, char **argv);
int			ft_isduplicated(t_list **stack, long long new);
void		ft_error(char *str);
void		ft_sort_three(t_list **stack);
void		ft_sort_two(t_list **stack);
void		ft_sort_stack(t_list **stack_a, t_list **stack_b);
int			ft_max(t_list *a);
int			ft_min(t_list *a);
int			ft_sum(t_list *stack);
bool		stack_sorted(t_list *stack);
void		ft_min_on_top(t_list **a);
//finders
t_list		*ft_find_node(int number, t_list *stack);
void		ft_find_target_in_b(t_list **ptr, t_list **stack_b);
void		ft_find_target_in_a(t_list **ptr, t_list **stack_a);
t_list		*ft_find_cheapest(t_list **stack);
//setters
void		ft_set_indexs(t_list **stack_a, t_list **stack_b);
void		ft_set_costs(t_list **stack_a, t_list **stack_b);
void		ft_set_upper(t_list **stack);
void		ft_refresh(t_list **stack_a, t_list **stack_b);
void		ft_set_targets(t_list **stack_a, t_list **stack_b);
void		ft_set_push_cost(t_list **stack_a);
int			ft_min_push_cost(t_list *stack);
#endif //PUSH_SWAP_H
