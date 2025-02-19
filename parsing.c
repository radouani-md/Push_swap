/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:50:54 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/19 16:41:08 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handel_arg(char **args)
{
	size_t	parent;
	size_t	child;

	parent = 0;
	while (args && args[parent])
	{
		child = 0;
		if ((args[parent][child] == '+' || args[parent][child] == '-')
			&& args[parent][child + 1] != '\0')
			child++;
		while (args[parent][child])
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
	size_t	i;
	char	*joined_args;
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
	if (handel_arg(alloc_args) == 0)
		return (write(2, "Error\n", 6), ft_free_all(alloc_args), NULL);
	return (alloc_args);
}

int	check_duplicate(t_list	**stack_node)
{
	t_list	*current;
	t_list	*cheker;

	current = *stack_node;
	while (current)
	{
		cheker = current->next;
		while (cheker)
		{
			if (current->data == cheker->data)
				return (0);
			cheker = cheker->next;
		}
		current = current->next;
	}
	return (1);
}

void	add_to_node(char **all_args, t_list **stack_node)
{
	size_t	i;
	long	value;

	i = 0;
	if (!all_args)
		return ;
	while (all_args[i])
	{
		value = md_atoi(all_args[i]);
		if (value > 2147483647 || value < -2147483648)
			return (write(2, "Error\n", 6),
				ft_free_a(all_args, i), ft_lstclear(stack_node));
		ft_lstadd_back(stack_node, ft_lstnew(value));
		free(all_args[i]);
		i++;
	}
	free(all_args);
	if (!check_duplicate(stack_node))
	{
		write(2, "Error\n", 6);
		ft_lstclear(stack_node);
	}
}
