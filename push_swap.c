/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:41:12 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/19 23:08:31 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_position	max_node(t_list *stack)
{
	int			size_node;
	int			max_posi;
	t_position	node;

	node.max = -2147483648;
	node.position = 0;
	max_posi = 0;
	size_node = ft_lstsize(stack);
	while (size_node)
	{
		if (stack->data > node.max)
		{
			node.max = stack->data;
			node.position = max_posi;
		}
		stack = stack->next;
		size_node--;
		max_posi++;
	}
	return (node);
}

void	is_emty(int argc, char **argv)
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
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

void	helper_main(int number_args, t_list *stack_a, t_list *stack_b)
{
	if (number_args == 2)
		swap_two(&stack_a);
	else if (number_args == 3)
		swap_three(&stack_a);
	else if (number_args == 4)
		swap_four(&stack_a, &stack_b);
	else if (number_args == 5)
		swap_five(&stack_a, &stack_b);
	else if (number_args > 5 && number_args <= 100)
	{
		index_args(&stack_a);
		pushing_maxing(&stack_a, &stack_b, 11);
	}
	else if (number_args > 100)
	{
		index_args(&stack_a);
		pushing_maxing(&stack_a, &stack_b, 35);
	}
	if (stack_a)
		ft_lstclear(&stack_a);
}

int	is_x_sorted(t_list **stack_a)
{
	t_list	*head;

	if (!*stack_a)
		return (0);
	head = *stack_a;
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		number_args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		is_emty(argc, argv);
		add_to_node(filter_arguments(argv), &stack_a);
		number_args = ft_lstsize(stack_a);
		if (is_x_sorted(&stack_a))
			return (0);
		helper_main(number_args, stack_a, stack_b);
	}
	return (0);
}
