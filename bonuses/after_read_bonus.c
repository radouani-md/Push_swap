/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_read_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:38:06 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/19 18:11:56 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_lsize(t_ops *lst)
{
	int		count;
	t_ops	*ptr;

	count = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

void	helper_aply(t_list **stack_a, t_list **stack_b, t_ops *opers)
{
	if (!ft_strcmp(opers->data, "sa\n"))
		sa(stack_a, 0);
	else if (!ft_strcmp(opers->data, "sb\n"))
		sb(stack_b, 0);
	else if (!ft_strcmp(opers->data, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(opers->data, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(opers->data, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(opers->data, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(opers->data, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(opers->data, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(opers->data, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(opers->data, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(opers->data, "rrr\n"))
		rrr(stack_a, stack_b, 0);
}

void	aply_ops(t_list **stack_a, t_list **stack_b, t_ops *opers)
{
	int		size_ops;

	if (!opers)
		return ;
	size_ops = ft_lsize(opers);
	while (size_ops)
	{
		helper_aply(stack_a, stack_b, opers);
		opers = opers->next;
		size_ops--;
	}
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
