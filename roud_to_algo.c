/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roud_to_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:38:36 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/20 11:24:36 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a_sorted(t_list **stack_a, t_list **stack_b)
{
	int			size_node;
	t_position	node;

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
		else if (((node.position) > size_node / 2))
		{
			while ((*stack_b)->data != node.max)
				rrb(stack_b, 1);
			pa(stack_a, stack_b, 1);
		}
	}
}

int	handel_count(t_list **stack_a)
{
	int		count;
	t_list	*head;
	int		semi_size;

	count = 0;
	semi_size = ft_lstsize(*stack_a) / 2;
	head = *stack_a;
	while (semi_size)
	{
		if (head->data > head->next->data)
			count++;
		head = head->next;
		semi_size--;
	}
	return (count);
}

void	normal_algo(t_list **stack_a, t_list **stack_b, int index, int range)
{
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
}

void	handel_algo(t_list **stack_a, t_list **stack_b, int index, int range)
{
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
			rra(stack_a, 1);
	}
}

void	pushing_maxing(t_list **stack_a, t_list **stack_b, int range)
{
	int	index;
	int	count;

	if (!stack_a)
		return ;
	index = 0;
	count = handel_count(stack_a);
	if (count > (ft_lstsize(*stack_a) / 3))
		handel_algo(stack_a, stack_b, index, range);
	else
		normal_algo(stack_a, stack_b, index, range);
	push_to_a_sorted(stack_a, stack_b);
}
