/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 11:49:14 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-17 11:49:14 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
#define CHECKER_BONUS_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_ops
{
	char			*data;
	struct s_ops	*next;
}	t_ops;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
void	reading_input(t_ops **operatios);
size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_free_all(char **str);
char	*md_strjoin(char *s1, char *s2);
char	*md_strdup(char *src);
char	**filter_arguments(char **arg_string);
size_t	md_strlen(char *s);
char	**md_split(char const *s, char c);
long	md_atoi(const char *str);
t_list	*ft_lstnew(int content);
t_list  *ft_lstlast_befor(t_list *lst);
int		add_to_node(char **all_args , t_list **stack_node);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list  *ft_lstlast(t_list *lst);
void	ft_free_a(char **str, int i);
void	ft_free_r_a(char **str, int i);
void	sa(t_list **stack_a, int k);
void	sb(t_list **stack_b, int k);
void	ss(t_list **stack_a, t_list **stack_b, int k);
void	pa(t_list **stack_a, t_list **stack_b, int k);
void	pb(t_list **stack_a, t_list **stack_b, int k);
void	ra(t_list **stack_a, int k);
void	rb(t_list **stack_b, int k);
void	rr(t_list **stack_a, t_list **stack_b, int k);
void	rra(t_list **stack_a, int k);
void	rrr(t_list **stack_a, t_list **stack_b, int k);
void	rrb(t_list **stack_b, int k);
void	aply_ops(t_list **stack_a, t_list **stack_b, t_ops *opers);

#endif