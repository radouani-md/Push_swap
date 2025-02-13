/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_opr_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 21:05:37 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-11 21:05:37 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int k)
{
	t_list *last_st;
	t_list *last_st_befor;
	t_list *one_st;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	one_st = *stack_a;
	last_st = ft_lstlast(*stack_a);
	last_st_befor = ft_lstlast_befor(*stack_a);
	last_st_befor->next = NULL;
	last_st->next = one_st;
	*stack_a = last_st;
	if (k == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int k)
{
	t_list *last_st;
	t_list *last_st_befor;
	t_list *one_st;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	one_st = *stack_b;
	last_st = ft_lstlast(*stack_b);
	last_st_befor = ft_lstlast_befor(*stack_b);
	last_st_befor->next = NULL;
	last_st->next = one_st;
	*stack_b = last_st;
	if (k == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int k)
{
	rra(stack_a, k);
	rrb(stack_b, k);
	if (k == 1)
		write(1, "rrr\n", 4);
}
