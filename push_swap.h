/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:41:17 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/19 16:49:53 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct position
{
	int				position;
	int				max;
}	t_position;

void		ft_free_all(char **str);
char		*md_strjoin(char *s1, char *s2);
char		*md_strdup(char *src);
char		**filter_arguments(char **arg_string);
size_t		md_strlen(char *s);
char		**md_split(char const *s, char c);
long		md_atoi(const char *str);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_free_a(char **str, int i);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst);
t_list		*ft_lstlast(t_list *lst);
void		add_to_node(char **all_args, t_list **stack_node);
void		sa(t_list **stack_a, int k);
void		sb(t_list **stack_b, int k);
void		ss(t_list **stack_a, t_list **stack_b, int k);
void		pa(t_list **stack_a, t_list **stack_b, int k);
void		pb(t_list **stack_a, t_list **stack_b, int k);
void		ra(t_list **stack_a, int k);
void		rb(t_list **stack_b, int k);
void		rr(t_list **stack_a, t_list **stack_b, int k);
void		rra(t_list **stack_a, int k);
void		rrr(t_list **stack_a, t_list **stack_b, int k);
void		rrb(t_list **stack_b, int k);
t_list		*ft_lstlast_befor(t_list *lst);
void		swap_three(t_list **stack_a);
void		swap_four(t_list **stack_a, t_list **stack_b);
void		swap_five(t_list **stack_a, t_list **stack_b);
void		index_args(t_list **stack_a);
void		pushing_maxing(t_list **stack_a, t_list **stack_b, int range);
void		rrb(t_list **stack_b, int k);
t_position	max_node(t_list *stack);
void		swap_two(t_list **stack_a);

#endif