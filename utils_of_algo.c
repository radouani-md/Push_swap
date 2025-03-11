/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_of_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:41:08 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/24 11:01:04 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_index_minus_one(t_list *head)
{
	while (head)
	{
		head->index = -1;
		head = head->next;
	}
}

void	index_args(t_list **stack_a)
{
	t_list	*head;
	t_list	*smallest;
	int		index;
	int		min_value;

	head = *stack_a;
	make_index_minus_one(head);
	index = 0;
	while (index < ft_lstsize(*stack_a))
	{
		head = *stack_a;
		smallest = NULL;
		min_value = 2147483647;
		while (head)
		{
			if (head->index == -1 && head->data <= min_value)
			{
				min_value = head->data;
				smallest = head;
			}
			head = head->next;
		}
		if (smallest)
			smallest->index = index++;
	}
}
