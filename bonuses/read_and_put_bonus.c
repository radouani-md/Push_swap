/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_put_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:11:41 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:34 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_ops	*ft_llast(t_ops *lst)
{
	t_ops	*last;

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

int	reading_input(t_ops **operatios)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strcmp(line, "sa\n") != 0 && ft_strcmp(line, "sb\n") != 0
			&& ft_strcmp(line, "ss\n") != 0 && ft_strcmp(line, "pa\n") != 0
			&& ft_strcmp(line, "pb\n") != 0 && ft_strcmp(line, "ra\n") != 0
			&& ft_strcmp(line, "rb\n") != 0 && ft_strcmp(line, "rr\n") != 0
			&& ft_strcmp(line, "rra\n") != 0 && ft_strcmp(line, "rrb\n") != 0
			&& ft_strcmp(line, "rrr\n") != 0)
		{
			write(2, "Error\n", 6);
			free(line);
			ft_lclear(operatios);
			get_next_line(-1);
			return (0);
		}
		ft_lst_back(operatios, ft_lnew(line));
	}
	return (1);
}
