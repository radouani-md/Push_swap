/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:50:36 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/19 16:50:45 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_three(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) != 3)
		return ;
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data)
		sa(stack_a, 1);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data)
		ra(stack_a, 1);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
		rra(stack_a, 1);
}

void	helper_four(t_list *head, t_list **stack_a, t_list	*less_one)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		if (head == less_one && count == 2)
			sa(stack_a, 1);
		else if (head == less_one && count == 3)
		{
			rra(stack_a, 1);
			rra(stack_a, 1);
		}
		else if (head == less_one && count == 4)
			rra(stack_a, 1);
		head = head->next;
	}
}

void	helper_five(t_list *head, t_list **stack_a, t_list	*less_one)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		if (head == less_one && count == 2)
			sa(stack_a, 1);
		else if (head == less_one && count == 3)
		{
			rra(stack_a, 1);
			rra(stack_a, 1);
			rra(stack_a, 1);
		}
		else if (head == less_one && count == 4)
		{
			rra(stack_a, 1);
			rra(stack_a, 1);
		}
		head = head->next;
	}
}

void	swap_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*less_one;
	t_list	*head;

	head = *stack_a;
	if (ft_lstsize(*stack_a) != 4)
		return ;
	less_one = *stack_a;
	while (head)
	{
		if (head->data < less_one->data)
			less_one = head;
		head = head->next;
	}
	head = *stack_a;
	helper_four(head, stack_a, less_one);
	pb(stack_a, stack_b, 1);
	swap_three(stack_a);
	pa(stack_a, stack_b, 1);
}

void	swap_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*less_one;
	t_list	*head;

	head = *stack_a;
	if (ft_lstsize(*stack_a) != 5)
		return ;
	less_one = *stack_a;
	while (head)
	{
		if (head->data < less_one->data)
			less_one = head;
		head = head->next;
	}
	head = *stack_a;
	helper_five(head, stack_a, less_one);
	pb(stack_a, stack_b, 1);
	swap_four(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}
