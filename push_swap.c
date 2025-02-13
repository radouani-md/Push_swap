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

void	print(t_list *lst)
{
	t_list *tmp;
	tmp = lst;
	while (tmp)
	{
		printf("{{%d}}\n", tmp->data);
		tmp = tmp->next;
	}
}
int main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list *stack_b = NULL;

	// ft_lstadd_back(&stack_b, ft_lstnew(4));
	// ft_lstadd_back(&stack_b, ft_lstnew(5));

	// ft_lstadd_back(&stack_b, ft_lstnew(2));
	// ft_lstadd_back(&stack_b, ft_lstnew(3));
	if (argc > 1)
	{
		add_to_node(filter_arguments(argv), &stack_a);
		// print(stack_a);
		// printf("-----\n");
		// print(stack_b);
		// printf("|____________|\n");
		swap_five(&stack_a, &stack_b);
		// printf("<--------------->\n");
		// print(stack_a);
		// printf("-----\n");
		// print(stack_b);
	}
}