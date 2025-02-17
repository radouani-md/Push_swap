/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_put_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 14:11:41 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-17 14:11:41 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_ops  *ft_llast(t_ops *lst)
{
	t_ops *last;

	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

t_ops	*ft_lnew(char *content)
{
	t_ops	*ptr;

	ptr = (t_ops *) malloc(sizeof(t_ops));
	if (!ptr)
		return (NULL);
	ptr->data = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lst_back(t_ops **lst, t_ops *new)
{
	t_ops	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_llast(*lst);
		last->next = new;
	}
}

void	reading_input(t_ops **operatios)
{
	char	*line;
	int		i;

	line = get_next_line(0);
	i = 0;
	while(line)
	{
		if (!line)
			ft_free_r_a(line, i);
		i++;
		if (ft_strcmp(line, "sa\n") != 0 && ft_strcmp(line, "sb\n") != 0 && ft_strcmp(line, "ss\n") != 0
			&& ft_strcmp(line, "pa\n") != 0 && ft_strcmp(line, "pb\n") != 0 && ft_strcmp(line, "ra\n") != 0
			&& ft_strcmp(line, "rb\n") != 0 && ft_strcmp(line, "rr\n") != 0 && ft_strcmp(line, "rra\n") != 0
			&& ft_strcmp(line, "rrb\n") != 0 && ft_strcmp(line, "rrr\n") != 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_lst_back(operatios, ft_lnew(line));
		line = get_next_line(0);
	}
}
