/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_opr_s_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:06:44 by mradouan          #+#    #+#             */
/*   Updated: 2025/02/19 16:25:05 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_list **stack_a, int k)
{
	t_list	*one_st;
	t_list	*two_st;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	one_st = *stack_a;
	two_st = (*stack_a)->next;
	one_st->next = two_st->next;
	two_st->next = one_st;
	*stack_a = two_st;
	if (k == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int k)
{
	t_list	*one_st;
	t_list	*two_st;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	one_st = *stack_b;
	two_st = (*stack_b)->next;
	one_st->next = two_st->next;
	two_st->next = one_st;
	*stack_b = two_st;
	if (k == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int k)
{	
	sa(stack_a, k);
	sb(stack_b, k);
	if (k == 1)
		write(1, "ss\n", 3);
}
