/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 08:41:12 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-06 08:41:12 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_position	max_node(t_list *stack)
{
	int size_node;
	int	max_posi;
	t_position node;

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

void	print(t_list *lst)
{
	t_list *tmp;
	tmp = lst;
	while (tmp)
	{
		printf("{{%d}}, [%d]\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
}
int main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list *stack_b = NULL;
	// t_position max;

	// ft_lstadd_back(&stack_b, ft_lstnew(4));
	// ft_lstadd_back(&stack_b, ft_lstnew(5));

	// ft_lstadd_back(&stack_b, ft_lstnew(2));
	// ft_lstadd_back(&stack_b, ft_lstnew(3));
	if (argc > 1)
	{
		add_to_node(filter_arguments(argv), &stack_a);
		index_args(&stack_a);
		// print(stack_a);
		// printf("-----\n");
		// print(stack_b);
		// printf("|____________|\n");
		pushing_maxing(&stack_a, &stack_b);
		// printf("<--------------->\n");
		// print(stack_a);
		// // max = max_node(stack_a);
		// printf("-----\n");
		// print(stack_b);
		// printf("\n");
		// // printf("%d\n%d\n", max.max, max.position);
	}
}