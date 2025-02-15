/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roud_to_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-13 13:38:36 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-13 13:38:36 by mradouan         ###   ########.fr       */
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

void index_args(t_list **stack_a)
{
    t_list *head;
    t_list *smallest;
    int index;
    int min_value;

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

void	push_to_a_sorted(t_list **stack_a, t_list **stack_b)
{
	int	size_node;
	t_position node;

	node = max_node(*stack_b);
	while (*stack_b)
	{
		size_node = ft_lstsize(*stack_b);
		node = max_node(*stack_b);
		if (((node.position) <= size_node / 2))
		{
			while ((*stack_b)->data != node.max)
				rb(stack_b, 1);
			pa(stack_a, stack_b, 1);
		}
		if (((node.position) > size_node / 2))
		{
			while ((*stack_b)->data != node.max)
				rrb(stack_b, 1);
			pa(stack_a, stack_b, 1);
		}
	}
}

void	pushing_maxing(t_list **stack_a, t_list **stack_b)
{
	int	range;
	int index;

	if (!stack_a)
		return ;
	range = 11;
	index = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= index)
		{
			pb(stack_a, stack_b, 1);
			index++;
		}
		else if ((*stack_a)->index <= (range + index))
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			index++;
		}
		else
			ra(stack_a, 1);
	}
	push_to_a_sorted(stack_a, stack_b);
}

