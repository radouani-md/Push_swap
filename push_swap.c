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

int main(int argc, char **argv)
{
	int	i = 0;
	char	**numbers;
	if (argc > 1)
	{
		numbers = filter_arguments(argv);
		while(numbers && numbers[i])
		{
			printf("%s\n", numbers[i]);
			free(numbers[i]);
			i++;
		}
		free(numbers);
	}
}