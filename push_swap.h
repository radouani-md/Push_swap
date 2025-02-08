/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 08:41:17 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-06 08:41:17 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


void	ft_free_all(char **str);
char	*md_strjoin(char *s1, char *s2);
char	*md_strdup(char *src);
char	**filter_arguments(char **arg_string);
size_t	md_strlen(char *s);
char	**md_split(char const *s, char c);
int		md_atoi(const char *str);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));



























#endif