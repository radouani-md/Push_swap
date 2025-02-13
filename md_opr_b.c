/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_opr_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 10:08:48 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-11 10:08:48 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int k)
{
	t_list *one_st_a;
	t_list *one_st_b;

	if (ft_lstsize(*stack_b) < 1)
		return ;
	one_st_b = *stack_b;
	one_st_a = *stack_a;
	*stack_b = (*stack_b)->next;
	one_st_b->next = one_st_a;
	*stack_a = one_st_b;
	if (k == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int k)
{
	t_list *one_st_a;
	t_list *one_st_b;

	if (ft_lstsize(*stack_a) < 1)
		return ;
	one_st_b = *stack_b;
	one_st_a = *stack_a;
	*stack_a = (*stack_a)->next;
	one_st_a->next = one_st_b;
	*stack_b = one_st_a;
	if (k == 1)
		write(1, "pb\n", 3);
}

void	ra(t_list **stack_a, int k)
{
	t_list *one_st;
	t_list *last_st;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	one_st = *stack_a;
	last_st = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)->next;
	last_st->next = one_st;
	one_st->next = NULL;
	if (k == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int k)
{
	t_list *one_st;
	t_list *last_st;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	one_st = *stack_b;
	last_st = ft_lstlast(*stack_b);
	*stack_b = (*stack_b)->next;
	last_st->next = one_st;
	one_st->next = NULL;
	if (k == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int k)
{
	ra(stack_a, k);
	rb(stack_b, k);
	if (k == 1)
		write(1, "rr\n", 3);
}
