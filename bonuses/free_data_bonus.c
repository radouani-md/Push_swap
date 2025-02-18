/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 15:40:40 by mradouan          #+#    #+#             */
/*   Updated: 2025-02-06 15:40:40 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free_all(char **str)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_a(char **str, int i)
{
	if (!str)
		return ;
	while(str[i])
		free(str[i++]);
	free(str);
}
void	ft_lclear(t_ops **lst)
{
	t_ops	*ptr;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
