/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 11:48:07 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-17 11:48:07 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int is_emty(int argc, char **argv)
{
	int i;
	int j;

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

void	print(t_ops *lst)
{
	t_ops *tmp;
	tmp = lst;
	while (tmp)
	{
		printf("%s", tmp->data);
		tmp = tmp->next;
	}
}

void	print_stack(t_list *lst)
{
	t_list *tmp;
	tmp = lst;
	while (tmp)
	{
		printf("{<- %d ->}\n", tmp->data);
		tmp = tmp->next;
	}
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
		if (!add_to_node(filter_arguments(argv), &stack_a) || !is_emty(argc, argv))
		{
			write(2, "Error\n", 6);
			return 1;
		}
		reading_input(&operations);
		get_next_line(-1);
		aply_ops(&stack_a, &stack_b, operations);
		if (is_x_sorted(&stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
		{
			if(stack_b)
				ft_lstclear(&stack_b);
			write(1, "KO\n", 3);
		}
		ft_lstclear(&stack_a);
		ft_lclear(&operations);
		// printf("-------------------\n");
		// print(operations);
		// printf("__________________\n");
		// printf("_-_-_-_-_-_-_-_-_-\n");
		// printf("__________________\n");
		// print_stack(stack_a);
		// printf("__________________\n");
		// print_stack(stack_b);
	}
}