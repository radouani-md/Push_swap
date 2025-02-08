/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 08:50:54 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-06 08:50:54 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handel_arg(char **args)
{
	size_t	parent;
	size_t	child;

	parent = 0;
	while(args[parent])
	{
		child = 0;
		if ((args[parent][child] == '+' || args[parent][child] == '-') && args[parent][child + 1] != '\0')
        	child++;
		while(args[parent][child])
		{
			if (!(args[parent][child] >= '0' && args[parent][child] <= '9'))
				return (0);
			child++;	
		}
		parent++;
	}
	return (1);
}


char	**filter_arguments(char **arg_string)
{
	size_t 	i;
	char 	*joined_args;
	char	**alloc_args;

	i = 1;
	joined_args = NULL;
	while (arg_string[i])
	{
		joined_args = md_strjoin(joined_args, arg_string[i]);
		joined_args = md_strjoin(joined_args, " ");
		i++;
	}
	alloc_args = md_split(joined_args, ' ');
	free(joined_args);
	if(handel_arg(alloc_args) == 0)
		return (write(2, "Error\n", 6),ft_free_all(alloc_args), NULL);
	return (alloc_args);
}

void	add_to_node(char **all_args)
{
	size_t	i;

	i = 0;
	while (all_args[i])
	{
		ft_lstnew((char *)all_args[i]);
		i++
	}
	
}