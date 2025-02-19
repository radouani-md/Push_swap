/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:48:07 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/19 16:15:32 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_emty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
			j++;
		if (argv[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	helper_main(t_list *stack_b)
{
	if (stack_b)
		ft_lstclear(&stack_b);
	write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_ops	*operations;

	stack_a = NULL;
	stack_b = NULL;
	operations = NULL;
	if (argc > 1)
	{
		if (!add_to_node(filter_arguments(argv), &stack_a)
			|| !is_emty(argc, argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (!reading_input(&operations))
			return (ft_lstclear(&stack_a), 1);
		aply_ops(&stack_a, &stack_b, operations);
		if (is_x_sorted(&stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			helper_main(stack_b);
		return (ft_lstclear(&stack_a), ft_lclear(&operations), 0);
	}
}
